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

#include "../gen_webpage/Indexer.h"

using namespace CppUnit;

class Indexer_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Indexer_test);
    CPPUNIT_TEST(set_word_test);
    CPPUNIT_TEST(op_sub_test);
    CPPUNIT_TEST(find_word_test);
    CPPUNIT_TEST(add_test);
    CPPUNIT_TEST(gen_webpage_test);
    CPPUNIT_TEST(op_out_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void set_word_test();
    void op_sub_test();
    void find_word_test();
    void add_test();
    void gen_webpage_test();
    void op_out_test();

private :
    Indexer idx_obj;
    Word non;
    Word w1, w2;
};

//===========================================================

void Indexer_test::setUp()
{
    w1.set_word("setUp");
    w1.set_count(1);
    w1.add_url("http://www.setUp.com");
    idx_obj.add(w1);
}

void Indexer_test::tearDown()
{
    ;// Keep test in case dynamic memory is used in future
 
}

void Indexer_test::set_word_test()
{
    w2.set_word("set_word");
    idx_obj.set_word(w1.get_word(), w2);
    CPPUNIT_ASSERT(idx_obj.find_word(w2.get_word(), non).get_word() == "set_word");
    CPPUNIT_ASSERT(idx_obj.find_word(w2.get_word(), non).get_count() == w1.get_count());
    CPPUNIT_ASSERT(idx_obj.find_word(w2.get_word(), non).get_url() == w1.get_url());
}

void Indexer_test::op_sub_test()
{
    Word w3("op_sub3", 3, "http://www.u1.com http://www.u2.com http://www.u3.com");
    idx_obj.add(w3);
    CPPUNIT_ASSERT(idx_obj[w3.get_word()].get_word() == "op_sub3");
    CPPUNIT_ASSERT(idx_obj[w3.get_word()].get_count() == 3);
    CPPUNIT_ASSERT(idx_obj[w3.get_word()].get_url() == "http://www.u1.com\nhttp://www.u2.com\nhttp://www.u3.com\n");
}

void Indexer_test::find_word_test()
{
    std::string str("find_word");
    w1.set_word(str);
    idx_obj.set_word(w2.get_word(), w1);
    CPPUNIT_ASSERT(idx_obj.find_word(str, non).get_word() == str);
}

void Indexer_test::add_test()
{
    Word u0, u1("u1", 1, "http://www.u1.com");

    idx_obj.add(u0);
    CPPUNIT_ASSERT(idx_obj.find_word(u0.get_word(), non).get_word() == "");

    idx_obj.add(u1);
    CPPUNIT_ASSERT(idx_obj.find_word(u1.get_word(), non).get_word() == "u1");
}

void Indexer_test::gen_webpage_test()
{
    Indexer idx_obj1;
    Word u0("gen_webpage0", 1, "http://www.gen_webpage0.com");
    Word u1("gen_webpage1", 2, "http://www.gen.com http://www.webpage.com");

    idx_obj1.add(u0);
    idx_obj1.add(u1);

    idx_obj1.gen_webpage();
    std::ifstream txt("webpages_idx/");
    std::string str1, str2;
    unsigned cnt(0);

    while(std::getline(txt, str1)){
        str2 += str1;
    }

    CPPUNIT_ASSERT(str2.find("gen_webpage0") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.gen_webpage0.com") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("gen_webpage1") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.gen.com") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.webpage.com") != std::string::npos);
}

void Indexer_test::op_out_test()
{
    ;//Consider redirecting STDOUT to test operator<<
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
