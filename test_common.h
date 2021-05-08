#pragma once

#ifndef TEST_COMMON_H
#define TEST_COMMON_H

#include <tuple>
#include <typeinfo>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>

//#include "triangle.h"

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
		:method_(method)
	{
		std::string name;
		int i = number;

		for (auto& data : data)
		{
			addTest(new MyTestCase(instance, func, data, method, i));
			i++;
		}
	}

private:
	const char* method_ = nullptr;

};

#endif // !TEST_COMMON_H
