//DATE : 04/04/15
//FILE : cpp_webpage_test.cpp
//DESC : Unit tests for <class_name> class

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

#include "cpp_webpage.h"

using namespace CppUnit;

class cpp_webpage_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(cpp_webpage_test);
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
    void title_test;
    void paragraph_test;
    void image_test;
    void link_test;
    void heading_test;

private :
    cpp_webpage cpp_obj;
};

//===========================================================

void cpp_webpage_test::setUp()
{

}

void cpp_webpage_test::tearDown()
{

}

void cpp_webpage_test::title_test
{

}

void cpp_webpage_test::paragraph_test
{

}

void cpp_webpage_test::image_test
{

}

void cpp_webpage_test::link_test
{

}

void cpp_webpage_test::heading_test
{

}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(cpp_webpage_test);

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

    std::ofstream xmlFileOut(<test_results_output_file>);
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
