#include "sale_test.h"

#include <climits>
#include <iostream>
#include <cmath>

#include <cppunit/TestAssert.h>

#include "../test_common.h"

const double EPS = 1e-6;

std::string doubleToString(const double &val)
{
	char *chCode;
	chCode = new char[20];
	sprintf(chCode, "%.2lf", val);
	std::string str(chCode);
	delete[] chCode;
	return str;
}

template <>
struct CppUnit::assertion_traits<Sale::Result>
{
	static bool equal(const Sale::Result &lhs, const Sale::Result &rhs)
	{
		return fabs(lhs.val - rhs.val) < EPS;
	}

	static std::string toString(const Sale::Result &val)
	{
		return doubleToString(val.val);
	}
};

constexpr int NORMAL_VAL = INT_MAX >> 1;
const std::vector<SaleTestData> TEST_CASE_BWR =
	{
		{-1, {0, 1, 1}},
		{10, {1, 1, 1}},
		{12.5, {2, 1, 1}},
		{50, {5, 5, 5}},
		{97.5, {9, 10, 10}},
		{100, {10, 10, 10}},
		{161.25, {10, 11, 11}},
		{263.25, {18, 18, 17}},
		{270, {18, 18, 18}},
		{365, {19, 18, 18}},
		{600, {30, 30, 30}},
		{1400, {70, 70, 70}},
		{1640, {70, 80, 90}},
		{-1, {71, 81, 91}},
};

SaleBoundaryTest::SaleBoundaryTest()
	: SaleTestSuite(&Sale::solve, TEST_CASE_BWR, Sale(),
					"Boundary Test")
{
}
