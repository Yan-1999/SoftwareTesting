#include <ostream>

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/TextOutputter.h>

#include "triangle_test.h"

int main(int argc, char* argv[])
{
	CppUnit::TestResult tr;
	CppUnit::TestResultCollector trc;
	tr.addListener(&trc);

	CppUnit::TestRunner runner;
	CppUnit::TestSuite* tbt_test_suite = new TriangleBoundaryTest();
	CppUnit::TestSuite* tect_test_suite = new TriangleEqvClassTest();
	runner.addTest(tbt_test_suite);
	runner.addTest(tect_test_suite);
	runner.run(tr);

	CppUnit::TextOutputter out(&trc, std::cout);
	out.write();

	return !trc.wasSuccessful();
}
