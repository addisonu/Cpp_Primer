//DATE : 04/04/15
//FILE : ubc_hash_test.cpp
//DESC : Unit tests for ubc_hash_test class

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

#include "../gen_webpage/web/URLConnection.h"
#include "../gen_webpage/web/CS240Exception.h"
#include "../gen_webpage/Hash_indexer.h"
#include "../gen_webpage/Word.h"
#include "../gen_webpage/ubc_hash.cpp"

using namespace CppUnit;

class ubc_hash_test : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(ubc_hash_test);
    CPPUNIT_TEST(parse_test);
    CPPUNIT_TEST(page_links_test);
    CPPUNIT_TEST(get_page_test);
    CPPUNIT_TEST(has_websuffix_test);
    CPPUNIT_TEST(has_webprefix_test);
    CPPUNIT_TEST(in_scope_test);
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

private :
    std::string url;
    std::string page_text;
    Hash_indexer words;
    std::set<std::string> found_words;
    std::map<std::string, char> urls;
};

//===========================================================

void ubc_hash_test::setUp()
{
    url = "../../test_pages/home_html";
    page_text = "test_download.txt";
}

void ubc_hash_test::tearDown()
{
    ;// Keep in case dynamic memory is incorporated
}

void ubc_hash_test::parse_test()
{
    std::string curr_url = "../../test_pages/ubc_test.html";
    std::string indexed_arr[] = {"there", "are", "a", "couple", "of", "great", "bubbles", "in", "my", "home", "bases", "of", "new york", "and", "la"};
    unsigned cnt(0);
    std::string *ptr = indexed_arr;
    found_words = parse(curr_url, page_text, words);

    for(const auto id_word : found_words)
        CPPUNIT_ASSERT(id_word == *(ptr++));
}

void ubc_hash_test::page_links_test()
{
    urls = page_links(url, page_text, words);
    std::string url_base = "add url for home.html from test_pages"; // debugging
    std::string url_arr[] = {"home.html", "tp1/tp2/h1.html", "tp1/h2.html", "tp1/tp3/h3.html", "tp1/h4.html", "tp2/h5.html", "h6.html", "tp2/no_title.html"};
    unsigned cnt(0);

    for(auto url : urls)
        CPPUNIT_ASSERT(true == urls[url_base + url_arr[cnt++]]);
}

void ubc_hash_test::get_page_test()
{
    CPPUNIT_ASSERT(true == !get_page(url, page_text, words));
}

void ubc_hash_test::has_websuffix_test()
{
    std::size_t pg_pos = 0;
    std::string html, htm, shtml, cgi, jsp, asp, aspx, php, pl, cfm;
    html = "http://www.url.html";
    htm = "http://www.url.htm";
    shtml = "http://www.url.shtml";
    cgi = "http://www.url.cgi";
    jsp = "http://url.jsp";
    asp = "file://url.asp";
    aspx  = "file://url.aspx";
    php = "file://url.php";
    pl = "file://url.pl";
    cfm = "file://url.cfm";

    CPPUNIT_ASSERT(true == has_websuffix(html, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(htm, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(shtml, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(cgi, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(jsp, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(asp, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(aspx, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(php, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(pl, pg_pos));
    CPPUNIT_ASSERT(true == has_websuffix(cfm, pg_pos));
}

void ubc_hash_test::has_webprefix_test()
{
    std::string str1("http://www.had_websuffix.com");
    std::string str2("file:///Users/had_websuffix.html");
    std::string str3("www.has_webprefix.com");

    CPPUNIT_ASSERT(true == has_webprefix(str1));
    CPPUNIT_ASSERT(true == has_webprefix(str2));
    CPPUNIT_ASSERT(false == has_webprefix(str3));
}

void ubc_hash_test::in_scope_test()
{
    std::string home("http://www.macys.com");
    std::string page1("http://www.macys.com/winter_clothes/boots");
    std::string page2("http://www.yummy.com");

    CPPUNIT_ASSERT(true == in_scope(home, page1));
    CPPUNIT_ASSERT(false == in_scope(home, page2));
}

//===========================================================

CPPUNIT_TEST_SUITE_REGISTRATION(ubc_hash_test);

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

    std::ofstream xmlFileOut("ubc_hash_test.xml");
    XmlOutputter xmlOut(&collectedresults, xmlFileOut);
    xmlOut.write();

    return collectedresults.wasSuccessful() ? 0 : 1;
}
