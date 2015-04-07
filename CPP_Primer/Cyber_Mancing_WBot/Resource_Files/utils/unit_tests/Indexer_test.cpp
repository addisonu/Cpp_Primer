//DATE : 04/04/15
//FILE : Indexer_test.cpp
//DESC : Unit tests for Indexer_test class

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

#include "Indexer.h"

using namespace CppUnit;

class Indexer_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Indexer_test);
    CPPUNIT_TEST(set_word_test);
    CPPUNIT_TEST(operator[]_test);
    CPPUNIT_TEST(find_word_test);
    CPPUNIT_TEST(add_test);
    CPPUNIT_TEST(gen_webpage_test);
    CPPUNIT_TEST(operator<<_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    set_word_test();
    void operator[]_test();
    void find_word_test();
    void add_test();
    void gen_webpage_test();
    void operator<<_test();

private :
    Indexer idx_obj;
};

//===========================================================

void Indexer_test::setUp()
{

}

void Indexer_test::tearDown()
{

}
void Indexer_test::set_word_test()
{

}

void Indexer_test::operator[]_test()
{

}

void Indexer_test::find_word_test()
{

}

void Indexer_test::add_test()
{

}

void Indexer_test::gen_webpage_test()
{

}

void Indexer_test::operator<<_test()
{

}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(Indexer_test);

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

    std::ofstream xmlFileOut("Indexer_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
