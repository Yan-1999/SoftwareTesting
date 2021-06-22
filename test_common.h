#pragma once

#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <tuple>
#include <typeinfo>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>
#include <tinyxml2.h>

//#include "triangle.h"

template<size_t I = 0, typename ...ArgTy>
void args2Xml(tinyxml2::XMLDocument* doc,
	tinyxml2::XMLElement* case_elem,
	const std::tuple<ArgTy...>& args)
{
	if constexpr (I == sizeof...(ArgTy))
	{
		return;
	}
	else
	{
		auto arg = std::get<I>(args);
		tinyxml2::XMLElement* param = doc->NewElement("Param");
		param->SetText(CppUnit::assertion_traits<decltype(arg)>().toString(arg)
			.c_str());
		case_elem->InsertEndChild(param);

		args2Xml<I + 1>(doc, case_elem, args);
	}
};

template<typename RetTy, typename ...ArgTy>
struct TestData
{
	RetTy exp_val_;
	std::tuple<ArgTy...> args_;
};

template<class Ty, typename RetTy, typename ...ArgTy>
class MyTestCase : public CppUnit::TestCase
{
	using TestClass = Ty;

public:

	MyTestCase(Ty& instance, RetTy(Ty::* func)(ArgTy...),
		const TestData<RetTy, ArgTy...>& data, const char* method = "",
		int number = 0)
		:TestCase(std::string(typeid(Ty).name()).append(" - ").append(method)
			.append(" ").append(std::to_string(number))),
		instance_(instance), func_(func), data_(data), number_(number)
	{
	}

	void runTest() override
	{
		RetTy exp_val = std::apply(func_, std::tuple_cat(std::make_tuple(instance_),
			data_.args_));
		std::stringstream ss;
		ss << "Input   : (";
		std::apply([&ss](auto... args) { ((ss << args << ','), ...); }, data_.args_);
		ss << ')' << std::flush;
		CPPUNIT_ASSERT_EQUAL_MESSAGE(ss.str(), exp_val, data_.exp_val_);
	}

	auto test_func() { return func_; }

	auto data() { return data_; }


private:
	Ty& instance_;
	RetTy(Ty::* func_)(ArgTy...);
	const TestData<RetTy, ArgTy...>& data_;
	const char* method_ = nullptr;
	int number_;
};

template<class Ty, typename RetTy, typename ...ArgTy>
class MyTestSuite : public CppUnit::TestSuite
{
	using TestClass = Ty;

public:
	MyTestSuite(RetTy(Ty::* func)(ArgTy...),
		const std::vector<TestData<RetTy, ArgTy...>>& data,
		Ty instance = Ty(), const char* method = "", int number = 0)
		:method_(method), data_(data)
	{
		std::string name;
		int i = number;

		for (auto& d : data)
		{
			addTest(new MyTestCase(instance, func, d, method, i));
			i++;
		}
	}

private:

public:

	std::string data2Xml()
	{
		tinyxml2::XMLDocument doc;
		tinyxml2::XMLPrinter printer;
		tinyxml2::XMLElement* root = doc.NewElement("Data");
		doc.InsertFirstChild(root);
		for (auto& d : data_)
		{
			tinyxml2::XMLElement* test_case = doc.NewElement("Case");
			tinyxml2::XMLElement* ret = doc.NewElement("Expected");
			ret->SetText(
				CppUnit::assertion_traits<RetTy>().toString(d.exp_val_)
				.c_str()
			);
			args2Xml(&doc, test_case, d.args_);
			test_case->InsertFirstChild(ret);
			root->InsertFirstChild(test_case);
		}
		doc.Print(&printer);
		return std::string(printer.CStr());
	}


private:
	std::vector<TestData<RetTy, ArgTy...>> data_;
	const char* method_ = nullptr;

};

#endif // !TEST_COMMON_H
