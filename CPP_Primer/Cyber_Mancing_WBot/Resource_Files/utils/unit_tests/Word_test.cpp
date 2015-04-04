//DATE : 04/01/15
//FILE : Word_test.cpp
//DESC : Unit tests for Word class

// LEFT OFF //
/*
 * Check tests are written correctly
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

#include "../gen_webpage/Word.h"

using namespace CppUnit;

class Word_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Word_test);
    CPPUNIT_TEST(test_get_word);
    CPPUNIT_TEST(test_set_word);
    CPPUNIT_TEST(test_get_count);
    CPPUNIT_TEST(test_get_url);
    CPPUNIT_TEST(test_add_url);
    CPPUNIT_TEST(test_empty);
    CPPUNIT_TEST(test_compound_add0);
    CPPUNIT_TEST(test_compound_add1);
    CPPUNIT_TEST(test_lower_word);
    CPPUNIT_TEST(test_is_stopword);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void test_get_word();
    void test_set_word();
    void test_get_count();
    void test_set_count();
    void test_get_url();
    void test_add_url();
    void test_empty();
    void test_compound_add0();
    void test_compound_add1();
    void test_lower_word();
    void test_is_stopword();

private :
    Word *pWord_test[3];
};

//===========================================================

void Word_test::setUp()
{
    pWord_test[0] = new Word();
    pWord_test[1] = new Word("Net");
    pWord_test[2] = new Word("Las", 2, "http://www.macys.com http://www.nordstroms.com");
}

void Word_test::tearDown()
{
    for(Word *pWord : pWord_test)
        delete pWord;
}

void Word_test::test_get_word()
{
    CPPUNIT_ASSERT("" == pWord_test[0]->get_word());
    CPPUNIT_ASSERT("net" == pWord_test[1]->get_word());
    CPPUNIT_ASSERT("las" == pWord_test[2]->get_word());
}

void Word_test::test_set_word()
{
    pWord_test[0]->set_word("Test");
    CPPUNIT_ASSERT("test" == pWord_test[0]->get_word());
    pWord_test[0]->set_word("Foo");
    CPPUNIT_ASSERT("foo" == pWord_test[0]->get_word());
}

void Word_test::test_get_count()
{
    CPPUNIT_ASSERT(2 == pWord_test[2]->get_count());
}

void Word_test::test_set_count()
{
    pWord_test[0]->set_count(10);
    CPPUNIT_ASSERT(10 == pWord_test[0]->get_count());
}

void Word_test::test_get_url()
{
    CPPUNIT_ASSERT("http://www.macys.com\nhttp://www.nordstroms.com\n" == pWord_test[2]->get_url());
}

void Word_test::test_add_url()
{
    pWord_test[0]->add_url("http://www.kungfu.com");
    CPPUNIT_ASSERT("http://www.kungfu.com\n" == pWord_test[0]->get_url());
}

void Word_test::test_empty()
{
    Word w;
    CPPUNIT_ASSERT(true == w.empty());
}

void Word_test::test_compound_add0()
{
// Test += for rhs Word with URL not contained in lhs Word

    pWord_test[0]->set_word("Las");
    std::size_t cnt = pWord_test[2]->get_count();
    *(pWord_test[2]) += *(pWord_test[0]);
    CPPUNIT_ASSERT("http://www.macys.com\nhttp://www.nordstroms.com\nhttp://www.kungfu.com\n" == pWord_test[2]->get_url());
    CPPUNIT_ASSERT(cnt == pWord_test[2]->get_count());
}
void Word_test::test_compound_add1()//const Word rhs);
{
// Test += for rhs Word with URL contained in lhs Word

    pWord_test[1]->set_word("Las");
    pWord_test[1]->add_url("http://www.macys.com");
    std::size_t cnt = pWord_test[2]->get_count();
    *pWord_test[2] += *pWord_test[1];
    //CPPUNIT_ASSERT("http://www.macys.com\nhttp://www.nordstroms.com\nhttp://www.kun    gfu.com\n" == pWord_test[2]->get_url() && (cnt + 1) == pWord_test[2]->get_count());
    CPPUNIT_ASSERT("las" == pWord_test[0]->get_word());
}

void Word_test::test_lower_word()
{
    std::string word = "STriNg";
    pWord_test[0]->lower_word(word);
    CPPUNIT_ASSERT("string" == word);
}

void Word_test::test_is_stopword()
{
    const char stop_file[] = "../../stop_words.txt";
    CPPUNIT_ASSERT(true == pWord_test[0]->is_stopword(stop_file, "and"));
}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(Word_test);

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

    std::ofstream xmlFileOut("Word_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
