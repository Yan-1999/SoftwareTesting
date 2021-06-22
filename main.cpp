#include <cstring>
#include <ostream>

//#include <cgicc/Cgicc.h>
//#include <cgicc/HTTPContentHeader.h>
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
	if (!std::strcmp(argv[1], "data"))
	{
		if (!std::strcmp(argv[2], "Triangle:solve:BoundaryTest"))
		{
			std::cout << TriangleBoundaryTest().data2Xml() << std::flush;
		}
		else if (!std::strcmp(argv[2], "Triangle:solve:EquivalentClassTest"))
		{
			std::cout << TriangleEqvClassTest().data2Xml() << std::flush;
		}
		else if (!std::strcmp(argv[2], "Sale:solve:BoundaryTest"))
		{
			std::cout << SaleBoundaryTest().data2Xml() << std::flush;
		}
		return 0;
	}

	std::stringstream ss;

	CppUnit::TestResult tr;
	CppUnit::TestResultCollector trc;
	tr.addListener(&trc);

	CppUnit::TestRunner runner;
	CppUnit::TestSuite* suite = nullptr;
	for (size_t i = 0; i < argc; i++)
	{
		if (!std::strcmp(argv[i], "Triangle:solve:BoundaryTest"))
		{
			suite = new TriangleBoundaryTest();
			runner.addTest(suite);
		}
		else if (!std::strcmp(argv[i], "Triangle:solve:EquivalentClassTest"))
		{
			suite = new TriangleEqvClassTest();
			runner.addTest(suite);
		}
		else if (!std::strcmp(argv[i], "Sale:solve:BoundaryTest"))
		{
			suite = new SaleBoundaryTest();
			runner.addTest(suite);
		}
	}
	runner.run(tr);

	CppUnit::XmlOutputter out(&trc, ss);
	out.write();
	std::string s = ss.str();
	//size_t index = s.find_last_of('?');
	//s.insert(index + 2, style_str);

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
	doc.DeleteChild(doc.FirstChild());
	doc.Print(&printer);

	//std::cout << cgicc::HTTPContentHeader("application/xml");
	std::cout << printer.CStr() << std::flush;

	return !trc.wasSuccessful();
}
