#pragma once

#ifndef SALE_TEST_H
#define SALE_TEST_H

#include <string>
#include <typeinfo>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>

#include "../test_common.h"
#include "sale.h"

using SaleTestData = TestData<Sale::Result, int, int, int>;
using SaleTestCase = MyTestCase<Sale, Sale::Result, int, int, int>;
using SaleTestSuite = MyTestSuite<Sale, Sale::Result, int, int, int>;

class SaleBoundaryTest : public SaleTestSuite
{
public:
	SaleBoundaryTest();
};

const double EPS = 1e-6;

std::string doubleToString(const double& val);

template <>
struct CppUnit::assertion_traits<Sale::Result>
{
	static bool equal(const Sale::Result& lhs, const Sale::Result& rhs)
	{
		return fabs(lhs.val - rhs.val) < EPS;
	}

	static std::string toString(const Sale::Result& val)
	{
		return doubleToString(val.val);
	}
};

#endif // !SALE_TEST_H
