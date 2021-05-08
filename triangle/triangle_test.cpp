#include "triangle_test.h"

#include <climits>
#include <iostream>

#include <cppunit/TestAssert.h>

#include "../test_common.h"

constexpr const char* TRIANGLE_TYPE_NAME[] =
{
	"NON",
	"SCALENE",
	"ISOSCELES",
	"EQUILATERAL",
};

using TriangleTestData = TestData<Triangle::Type, int, int, int>;
using TriangleTestCase = MyTestCase<Triangle, Triangle::Type, int, int, int>;

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

constexpr int NORMAL_VAL = INT_MAX >> 1;
const std::vector<TriangleTestData> TEST_CASE_BWR =
{
	{Triangle::Type::NON, {0, NORMAL_VAL, NORMAL_VAL} },
	{Triangle::Type::ISOSCELES, {1, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::ISOSCELES, {2, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::NON, {INT_MAX - 1, NORMAL_VAL, NORMAL_VAL} },
	{Triangle::Type::NON, {INT_MAX, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::NON, {-1, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, 0, NORMAL_VAL}},
	{Triangle::Type::ISOSCELES, {NORMAL_VAL, 1, NORMAL_VAL}},
	{Triangle::Type::ISOSCELES, {NORMAL_VAL, 2, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, INT_MAX - 1, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, INT_MAX, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, -1, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, 0}},
	{Triangle::Type::ISOSCELES, {NORMAL_VAL, NORMAL_VAL, 1}},
	{Triangle::Type::ISOSCELES, {NORMAL_VAL, NORMAL_VAL, 2}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, INT_MAX - 1}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, INT_MAX}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, -1}},
	{Triangle::Type::EQUILATERAL, {NORMAL_VAL, NORMAL_VAL, NORMAL_VAL}},
};

const std::vector<TriangleTestData> TEST_CASE_EQV =
{
	{Triangle::Type::EQUILATERAL, {NORMAL_VAL, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::ISOSCELES, {1, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::SCALENE, {3, 4, 5}},
	{Triangle::Type::NON, {0, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::NON, {-1, NORMAL_VAL, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, 0, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, -1, NORMAL_VAL}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, 0}},
	{Triangle::Type::NON, {NORMAL_VAL, NORMAL_VAL, -1}},
};

TriangleBoundaryTest::TriangleBoundaryTest()
	:TriangleTestSuite(&Triangle::solve, TEST_CASE_BWR, Triangle(),
		"Boundary Test")
{
}

TriangleEqvClassTest::TriangleEqvClassTest()
	: TriangleTestSuite(&Triangle::solve, TEST_CASE_EQV, Triangle(),
		"Equivalent Class Test")
{
}
