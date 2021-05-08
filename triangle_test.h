#pragma once

#ifndef TRIANLGE_TEST_H
#define TRIANLGE_TEST_H

#include <string>
#include <typeinfo>
#include <vector>

#include <cppunit/TestCase.h>
#include <cppunit/TestSuite.h>

#include "test_common.h"
#include "triangle.h"


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

#endif // !TRIANLGE_TEST_H
