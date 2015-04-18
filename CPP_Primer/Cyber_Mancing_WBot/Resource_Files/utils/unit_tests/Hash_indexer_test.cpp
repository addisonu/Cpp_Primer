//DATE : 04/04/15
//FILE : Hash_indexer_test.cpp
//DESC : Unit tests for Hash_indexer class

// LEFT OFF //
/*
 * All unit tests pass except gen_webpage_test; gen_webpage() functions correctly when tested without CppUnit framework
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

#include "../gen_webpage/Hash_indexer.h"

using namespace CppUnit;

class Hash_indexer_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(Hash_indexer_test);
    CPPUNIT_TEST(set_word_test);
    CPPUNIT_TEST(get_word_test);
    CPPUNIT_TEST(get_size_test);
    CPPUNIT_TEST(find_word_test);
    CPPUNIT_TEST(add_test);
    CPPUNIT_TEST(gen_webpage_test);
    CPPUNIT_TEST(hash_word_test);
    CPPUNIT_TEST(op_out_test);
    CPPUNIT_TEST_SUITE_END();

public :
    void setUp();
    void tearDown();

protected :
    void set_word_test();
    void get_word_test();
    void get_size_test();
    void find_word_test();
    void add_test();
    void gen_webpage_test();
    void hash_word_test();
    void op_out_test();

private :
    Hash_indexer hash_obj;
    Word w1, w2;
    Word non;
};

//===========================================================

void Hash_indexer_test::setUp()
{
    w1.set_word("setUp");
    w1.set_count(1);
    w1.add_url("http://www.setUp.com");
    hash_obj.add(w1);
}

void Hash_indexer_test::tearDown()
{
    ;// Keep test in case dynamic memory is used in future
}

void Hash_indexer_test:: set_word_test()
{
    w2.set_word("set_word");
    w2.set_count(1);
    w2.add_url("http://www.set_word.com");
    hash_obj.add(w2);
    node<Word> *pwd = hash_obj.find_word(w2.get_word());
    CPPUNIT_ASSERT(pwd->data().get_word() == w2.get_word());
    CPPUNIT_ASSERT(pwd->data().get_count() == w2.get_count());
    CPPUNIT_ASSERT(pwd->data().get_url() == w2.get_url());
}

void Hash_indexer_test:: get_word_test()
{
    w1.set_word("get_word");
    hash_obj.add(w1);
    CPPUNIT_ASSERT(hash_obj.find_word(w1.get_word())->data().get_word() == "get_word");
}

void Hash_indexer_test:: get_size_test()
{
    Hash_indexer hash_obj1;
    w1.set_word("get_size1");
    w2.set_word("get_size2");
    Word w3("get_size3", 1, "http://www.get_size.com");
    hash_obj1.add(w1);
    hash_obj1.add(w2);
    hash_obj1.add(w3);
    CPPUNIT_ASSERT(hash_obj1.get_size(w1.get_word()) == 3);
}

void Hash_indexer_test:: find_word_test()
{
    w2.set_word("find_word");
    hash_obj.add(w2);
    CPPUNIT_ASSERT(hash_obj.find_word(w2.get_word())->data().get_word() == "find_word");
}

void Hash_indexer_test:: add_test()
{
    w1.set_word("add");
    hash_obj.add(w1);
    CPPUNIT_ASSERT(hash_obj.find_word(w1.get_word())->data().get_word() == "add");
}

void Hash_indexer_test:: gen_webpage_test()
{
    Hash_indexer hash_obj1;
    Word u0("agen_webpage0", 1, "http://www.gen_webpage0.com");

    hash_obj1.add(u0);

    hash_obj1.gen_webpage();
    std::ifstream txt("webpages/hash.html");
    txt.open("webpages/hash.html");
    std::string str1, str2;

    while(std::getline(txt, str1)){
        str2 += str1;
    }

    CPPUNIT_ASSERT(str2.find("gen_webpage0") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.gen_webpage0.com") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("gen_webpage1") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.gen.com") != std::string::npos);
    CPPUNIT_ASSERT(str2.find("http://www.webpage.com") != std::string::npos);
}

void Hash_indexer_test:: hash_word_test()
{
    w1.set_word("zzyx");
    w2.set_word("aaron");

    CPPUNIT_ASSERT(hash_obj.hash_word(w1.get_word()) == 675);
    CPPUNIT_ASSERT(hash_obj.hash_word(w2.get_word()) == 0);
}

void Hash_indexer_test:: op_out_test()
{
    ;//Consider redirecting STDOUT to test operator<<
}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(Hash_indexer_test);

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

    std::ofstream xmlFileOut("Hash_indexer_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
