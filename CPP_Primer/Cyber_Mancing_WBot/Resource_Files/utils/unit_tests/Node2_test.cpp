//DATE : 04/04/15
//FILE : Node2_test.cpp
//DESC : Unit tests for Node2_test class

// LEFT OFF //
/*
 * Fleshing out test member functions
 * Fix operator== for Word object to test list_search
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

#include "../gen_webpage/node2.h"
#include "../gen_webpage/Word.h"

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
    node<Word> *node_obj;
    Word w1;
    Word w2;
};

//===========================================================

void Node2_test::setUp()
{
    w1.set_word("setUp");
    w1.set_count(1);
    w1.add_url("http://www.setUp.com");
    node_obj->set_data(w1);
}

void Node2_test::tearDown()
{
    list_clear(node_obj);
}

void Node2_test::data_test()
{
    Word w("data", 1, "http://www.data.com");
    w1 = w;
    node_obj->set_data(w1);
    CPPUNIT_ASSERT(node_obj->data().get_word() == "data");
    CPPUNIT_ASSERT(node_obj->data().get_count() == 1);
    CPPUNIT_ASSERT(node_obj->data().get_url() == "http://www.data.com\n");
}

void Node2_test::link_test()
{
   CPPUNIT_ASSERT(node_obj->link() == NULL);

   Word w("link", 2, "http://www.link.com http://www.url.com");
   w2 = w;
   list_insert(node_obj, w2);

   CPPUNIT_ASSERT(node_obj->link()->data().get_word() == "link");
   CPPUNIT_ASSERT(node_obj->link()->data().get_count() == 2);
   CPPUNIT_ASSERT(node_obj->link()->data().get_url() == "http://www.link.com\nhttp://www.url.com\n");
}

void Node2_test::set_data_test()
{
    CPPUNIT_ASSERT(node_obj->link() != NULL);

    Word w3("set_data", 3, "http://www.data.com http://www.set.com http://www.third.com");
    node_obj->link()->set_data(w3);

    CPPUNIT_ASSERT(node_obj->link()->data().get_word() == "set_data");
    CPPUNIT_ASSERT(node_obj->link()->data().get_count() == 3);
    CPPUNIT_ASSERT(node_obj->link()->data().get_url() == "http://www.link.com\nhttp://www.url.com\nhttp://www.third.com\n");
}

void Node2_test::set_link_test()
{
    node<Word> link_node;
    node_obj->set_link(&link_node);
    CPPUNIT_ASSERT(node_obj->link() == &link_node);
}

void Node2_test::link_clear_test()
{
    tearDown();
    CPPUNIT_ASSERT(node_obj == NULL);
}

void Node2_test::list_copy_test()
{
    typedef node<Word>* pnode;
    pnode head_copy, tail_copy;
    Word w("new head_ptr", 0, "");
    node_obj = new node<Word>(w);
    list_insert(node_obj, w1);
    list_insert(node_obj, w2);

    list_copy(node_obj, head_copy, tail_copy);

    pnode tmp_node_cp = head_copy;
    pnode tmp_node_og = head_copy;

    while(tmp_node_og->link()){
        CPPUNIT_ASSERT(tmp_node_cp == tmp_node_og);
        tmp_node_cp = tmp_node_cp->link();
        tmp_node_og = tmp_node_og->link();
    }
}

void Node2_test::list_head_insert_test()
{
    Word w("list_head_insert", 1, "http://www.list_head.com");
    list_head_insert(node_obj, w);
    CPPUNIT_ASSERT(node_obj->data().get_word() == "list_head_insert");
    CPPUNIT_ASSERT(node_obj->data().get_count() == 1);
    CPPUNIT_ASSERT(node_obj->data().get_url() == "http://www.list_head.com\n");
}

void Node2_test::list_head_remove_test()
{
    Word w("list_head_remove", 1, "http://www.list_head_remove.com");
    list_insert(node_obj, w);
    list_head_remove(node_obj);
    CPPUNIT_ASSERT(node_obj->data().get_word() == "list_head_remove");
    CPPUNIT_ASSERT(node_obj->data().get_count() == 1);
    CPPUNIT_ASSERT(node_obj->data().get_url() == "http://www.list_head_remove.com\n");
}

void Node2_test::list_insert_test()
{
    Word w("list_insert", 2, "http://www.list_in.com http://www.list_sert.com");
    list_insert(node_obj, w);

    CPPUNIT_ASSERT(node_obj->link()->data().get_word() == "list_insert");
    CPPUNIT_ASSERT(node_obj->link()->data().get_count() == 2);
    CPPUNIT_ASSERT(node_obj->link()->data().get_url() == "http://www.list_in.com\nhttp://www.list_sert.com\n");
}

void Node2_test::list_remove_test()
{
    Word u1("list_remove1", 2, "http://www.list_in.com http://www.list_sert.com");
    Word u2("list_remove2", 1, "http://www.list_head_remove.com");
    node_obj->set_data(u2);
    list_insert(node_obj, u1);

    CPPUNIT_ASSERT(node_obj->data().get_word() == "list_remove2");
    CPPUNIT_ASSERT(node_obj->data().get_count() == 1);
    CPPUNIT_ASSERT(node_obj->data().get_url() == "http://www.list_head_remove.com");

    list_remove(node_obj);

    CPPUNIT_ASSERT(node_obj->data().get_word() == "list_remove1");
    CPPUNIT_ASSERT(node_obj->data().get_count() == 2);
    CPPUNIT_ASSERT(node_obj->data().get_url() == "http://www.list_in.com\nhttp://www.list_sert.com\n");
}

void Node2_test::list_search_test()
{
    Word u1("list_search", 2, "http://www.list_sea.com http://www.list_reach.com");
    list_insert(node_obj, u1);
    CPPUNIT_ASSERT(list_search(node_obj, u1)->data() == u1);
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
