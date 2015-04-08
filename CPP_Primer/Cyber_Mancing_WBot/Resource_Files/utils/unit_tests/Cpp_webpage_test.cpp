//DATE : 04/04/15
//FILE : Cpp_webpage_test.cpp
//DESC : Unit tests for Cpp_webpage_test class

// LEFT OFF //
/*
 * Fleshing out test member functions
 */

// Library and CppUnit header files

#include <iostream>
#include <string>
#include <list>
#include <cppunit/TestCase.h>
#include <cppunit/TestFixture.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <netinet/in.h>

// Class header files

#include "../gen_webpage/cpp_webpage.h"

using namespace CppUnit;

class Cpp_webpage_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Cpp_webpage_test);
    CPPUNIT_TEST(title_test);
    CPPUNIT_TEST(paragraph_test);
    CPPUNIT_TEST(image_test);
    CPPUNIT_TEST(link_test);
    CPPUNIT_TEST(heading_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void title_test();
    void paragraph_test();
    void image_test();
    void link_test();
    void heading_test();

private :
    Cpp_webpage cpp_obj;
};

//===========================================================

// Test constructors
void Cpp_webpage_test::setUp()
{
    Cpp_webpage cpw1;

    std::fstream txt("webpages/0.html", std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::string str = "a b c d e f g", str1, str2;
    std::stringstream ss;
    ss << "<!DOCTYPE html>\n<html>\nwebpages/0.html\n</head>\n<body>\n<h1></h1>\na b c d e f g\n</body>\n</html>";

    Cpp_webpage cpw2("test webpage", "This is a test ... t    esting", 1, txt, str);
    bool output = true;

    while(std::getline(txt, str1)){
        ss >> str2;
        if(str1 != str2){
            output = false;
            break;
        }
    }
    CPPUNIT_ASSERT(output);
}

void Cpp_webpage_test::tearDown()
{
    ;
}

void Cpp_webpage_test::title_test()
{
    std::string str("title");
    std::string title("<title>" + str + "</title>");
    cpp_obj.title(str);
    CPPUNIT_ASSERT(cpp_obj.get_result().find(title) != std::string::npos);
}

void Cpp_webpage_test::paragraph_test()
{
    std::fstream txt("webpages/0.html", std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::string str = "p a r a g r a p h e r", str1;
    str1 = "p<br>a<br>r<br>a<br>g<br>r<br>a<br>p<br>h<br>e<br>r<br>";
    cpp_obj.paragraph(txt, str);
    std::getline(txt, str1);
    CPPUNIT_ASSERT(str == str1);
}

void Cpp_webpage_test::image_test()
{
    std::string str("image_test");
    cpp_obj.image(str);
    str = "<img src=\"" + str + "\" />\n";
    CPPUNIT_ASSERT((cpp_obj.get_result().find(str)) != std::string::npos);
}

void Cpp_webpage_test::link_test()
{
    std::string URL("http://www.test_url"), str, label;
    str = "<a href=\"" + URL + "\"></a>\n";
    cpp_obj.link(URL, label);
    CPPUNIT_ASSERT(cpp_obj.get_result().find(str) != std::string::npos);

    label = "label";
    cpp_obj.link(URL, label);
    str = "<a href=\"" + URL + "\">" + label + "</a>\n";
    CPPUNIT_ASSERT(cpp_obj.get_result().find(str) != std::string::npos);
}

void Cpp_webpage_test::heading_test()
{
    std::string label("label");
    unsigned num(2);
    std::stringstream str;
    str << "<h" << num << ">" << label << "</h" << num << ">\n";
    cpp_obj.heading(num, label);
    CPPUNIT_ASSERT(cpp_obj.get_result().find(str.str()) != std::string::npos);
}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(Cpp_webpage_test);

int main(int argc, char **argv)
{
    CPPUNIT_NS::TestResult testresult;

    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener(&collectedresults);

    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener(&progress);

    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest(CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write();

    std::ofstream xmlFileOut("Cpp_webpage_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
