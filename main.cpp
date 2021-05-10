#include <ostream>

#include <cgicc/Cgicc.h>
#include <cgicc/HTTPContentHeader.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/XMLOutputter.h>

#include "triangle/triangle_test.h"

int main(int argc, char* argv[])
{
	cgicc::Cgicc cgi;
	std::stringstream ss;
	const char* style_str = "<?xml-stylesheet type=\"text/xsl\" href=\"/test.xsl\"?>";

	CppUnit::TestResult tr;
	CppUnit::TestResultCollector trc;
	tr.addListener(&trc);

	CppUnit::TestRunner runner;
	CppUnit::TestSuite* tbt_test_suite = new TriangleBoundaryTest();
	CppUnit::TestSuite* tect_test_suite = new TriangleEqvClassTest();
	runner.addTest(tbt_test_suite);
	runner.addTest(tect_test_suite);
	runner.run(tr);

	CppUnit::XmlOutputter out(&trc, ss);
	out.write();
	std::string s = ss.str();
	size_t index = s.find_last_of('?');
	s.insert(index + 2, style_str);
	std::cout << cgicc::HTTPContentHeader("application/xml");
	std::cout << s << std::flush;

	return !trc.wasSuccessful();
}
