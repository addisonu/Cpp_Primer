//DATE : 04/04/15
//FILE : Node2_test.cpp
//DESC : Unit tests for Node2_test class

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

#include "node2.h"

using namespace CppUnit;

class Node2_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Node2_test);
    CPPUNIT_TEST(data_test);
    CPPUNIT_TEST(link_test);
    CPPUNIT_TEST(set_data_test);
    CPPUNIT_TEST(set_link_test);
    CPPUNIT_TEST(link_clear_test);
    CPPUNIT_TEST(list_copy_test);
    CPPUNIT_TEST(list_head_insert_test);
    CPPUNIT_TEST(list_head_remove_test);
    CPPUNIT_TEST(list_insert_test);
    CPPUNIT_TEST(list_remove_test);
    CPPUNIT_TEST(list_search_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void data_test();
    void link_test();
    void set_data_test();
    void set_link_test();
    void link_clear_test();
    void list_copy_test();
    void list_head_insert_test();
    void list_head_remove_test();
    void list_insert_test();
    void list_remove_test();
    void list_search_test();

private :
    node<Word> node_obj;
};

//===========================================================

void Node2_test::setUp()
{

}

void Node2_test::tearDown()
{

}

void Node2_test::data_test()
{

}

void Node2_test::link_test()
{

}

void Node2_test::set_data_test()
{

}

void Node2_test::set_link_test()
{

}

void Node2_test::link_clear_test()
{

}

void Node2_test::list_copy_test()
{

}

void Node2_test::list_head_insert_test()
{

}

void Node2_test::list_head_remove_test()
{

}

void Node2_test::list_insert_test()
{

}

void Node2_test::list_remove_test()
{

}

void Node2_test::list_search_test()
{

}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(Node2_test);

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

    std::ofstream xmlFileOut("Node2_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
