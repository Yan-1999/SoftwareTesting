#include <ostream>

#include <cgicc/Cgicc.h>
#include <cgicc/HTTPContentHeader.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/XMLOutputter.h>
#include <tinyxml2.h>

#include "triangle/triangle_test.h"
#include "sale/sale_test.h"

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
	CppUnit::TestSuite* sbt_test_suite = new SaleBoundaryTest();
	runner.addTest(tbt_test_suite);
	runner.addTest(tect_test_suite);
	runner.addTest(sbt_test_suite);
	runner.run(tr);

	CppUnit::XmlOutputter out(&trc, ss);
	out.write();
	std::string s = ss.str();
	size_t index = s.find_last_of('?');
	s.insert(index + 2, style_str);

	tinyxml2::XMLDocument doc;
	doc.Parse(s.c_str());
	tinyxml2::XMLElement* class_num_node = doc.NewElement("TestClassNum");
	class_num_node->SetText(2);
	doc.RootElement()->FirstChildElement("Statistics")
		->InsertFirstChild(class_num_node);
	tinyxml2::XMLElement* set_num_node = doc.NewElement("TestSetNum");
	set_num_node->SetText(3);
	doc.RootElement()->FirstChildElement("Statistics")
		->InsertFirstChild(set_num_node);
	tinyxml2::XMLPrinter printer;
	doc.Print(&printer);

	std::cout << cgicc::HTTPContentHeader("application/xml");
	std::cout << printer.CStr() << std::flush;

	return !trc.wasSuccessful();
}
