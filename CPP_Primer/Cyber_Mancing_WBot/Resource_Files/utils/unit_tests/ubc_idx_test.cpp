//DATE : 04/04/15
//FILE : ubc_idx_test.cpp
//DESC : Unit tests for <class_name> class

// LEFT OFF //
/*
 * Fleshing out test member functions
 */

// Library and CppUnit header files

#include <iostream>
#include <string>
#include <list>
#include <fstream>
#include <set>
#include <sstream>
#include <queue>
#include <map>
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

#include "web/URLConnection.h"
#include "web/CS240Exception.h"
#include "../../test_pages/build_url.cpp"
#include "Indexer.h"
#include "Word.h"

using namespace CppUnit;

class ubc_idx_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ubc_idx_test);
    CPPUNIT_TEST(parse_test);
    CPPUNIT_TEST(page_links_test);
    CPPUNIT_TEST(get_page_test);
    CPPUNIT_TEST(has_websuffix_test);
    CPPUNIT_TEST(has_webprefix_test);
    CPPUNIT_TEST(in_scope_test);
    CPPUNIT_TEST(find_url_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void parse_test();
    void page_links_test();
    void get_page_test();
    void has_websuffix_test();
    void has_webprefix_test();
    void in_scope_test();
    void find_url_test();

private :
    std::string url;
    std::string page_text;
    Indexer words;
    std::map<std::string, char> urls;
};

//===========================================================

void ubc_idx_test::setUp()
{

}

void ubc_idx_test::tearDown()
{

}
void ubc_idx_test::parse()
{

}

void ubc_idx_test::page_links()
{

}

void ubc_idx_test::get_page()
{

}

void ubc_idx_test::has_websuffix()
{

}

void ubc_idx_test::has_webprefix()
{

}

void ubc_idx_test::in_scope()
{

}

void ubc_idx_test::find_url()
{

}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(ubc_idx_test);

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

    std::ofstream xmlFileOut("ubc_idx_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
