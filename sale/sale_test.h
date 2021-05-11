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

#endif // !SALE_TEST_H
