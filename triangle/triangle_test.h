#pragma once

#ifndef TRIANLGE_TEST_H
#define TRIANLGE_TEST_H

#include <string>
#include <typeinfo>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>

#include "../test_common.h"
#include "triangle.h"

constexpr const char* TRIANGLE_TYPE_NAME[] =
{
	"NON",
	"SCALENE",
	"ISOSCELES",
	"EQUILATERAL",
};


using TriangleTestData = TestData<Triangle::Type, int, int, int>;
using TriangleTestCase = MyTestCase<Triangle, Triangle::Type, int, int, int>;
using TriangleTestSuite = MyTestSuite<Triangle, Triangle::Type, int, int, int>;

class TriangleBoundaryTest : public TriangleTestSuite
{
public:
	TriangleBoundaryTest();
};

class TriangleEqvClassTest : public TriangleTestSuite
{
public:
	TriangleEqvClassTest();
};

template<>
struct CppUnit::assertion_traits<Triangle::Type>
{
	static bool equal(const Triangle::Type& lhs, const Triangle::Type& rhs)
	{
		return lhs == rhs;
	}

	static std::string toString(const Triangle::Type& type)
	{
		return TRIANGLE_TYPE_NAME[(char)type];
	}
};


#endif // !TRIANLGE_TEST_H
