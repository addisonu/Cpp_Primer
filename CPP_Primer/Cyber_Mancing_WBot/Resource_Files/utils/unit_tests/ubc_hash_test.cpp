//DATE : 04/04/15
//FILE : ubc_hash_test.cpp
//DESC : Unit tests for ubc_hash_test class

// LEFT OFF //
/*
 * All unit tests pass
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
    std::string curr_url;
    std::string page_text;
    Hash_indexer words;
    std::set<std::string> found_words;
    std::map<std::string, char> urls;
    Word non;
};

//===========================================================

void ubc_hash_test::setUp()
{
    curr_url = ("http://www.bobateahouse.net");
    page_text = "../gen_webpage/test_download.txt";
}

void ubc_hash_test::tearDown()
{
    ;// Keep in case dynamic memory is incorporated
}

void ubc_hash_test::parse_test()
{
    curr_url = "file://<replace>/Resource_Files/test_pages/test_out.html";
    page_text = "webpages/test_out.txt";
    parse(curr_url, page_text, words);
    std::ifstream txt1(page_text.c_str());

    if(txt1.is_open()){
        std::string str, pos;
        char ch(' ');
        bool start = false;
        parse(curr_url, page_text, words);

        txt1 >> std::noskipws;
        while(txt1 >> ch){
            if(ch == '<'){
                while((txt1 >> ch) && ch != '>')
                    pos += ch;
                pos += ch;
                if(pos.find("/body>") != std::string::npos)
                    start = false;
                else if(pos.find("body>") != std::string::npos)
                    start = true;
                pos = "";
            }
            else if(start){
                if(ch == '>')
                    txt1 >> ch;
                else if(isspace(ch)){
                    if(!str.empty() && !non.is_stopword("../../stop_words.txt", str)){
                        //std::cout << "word = " << str << std::endl; // keep for debugging
                        CPPUNIT_ASSERT(words.find_word(str) != NULL);
                        str = "";
                    }
                    else
                        str = "";
                }
                else if(!ispunct(ch))
                    str+= tolower(ch);
            }
        }
    }
}

void ubc_hash_test::page_links_test()
{
    std::string test_urls[8];

    test_urls[0] = "file://<replace>/resource_files/test_pages/h6.html";
    test_urls[1] = "file://<replace>/resource_files/test_pages/home.html";
    test_urls[2] = "file://<replace>/resource_files/test_pages/tp1/h2.html";
    test_urls[3] = "file://<replace>/resource_files/test_pages/tp1/h4.html";
    test_urls[4] = "file://<replace>/resource_files/test_pages/tp1/tp3/h1.html";
    test_urls[5] = "file://<replace>/resource_files/test_pages/tp1/tp3/h3.html";
    test_urls[6] = "file://<replace>/resource_files/test_pages/tp2/h5.html";
    test_urls[7] = "file://<replace>/resource_files/test_pages/tp2/no_title.html";

    curr_url = *test_urls;
    page_text = "webpages/page_links_out.txt";
    urls = page_links(curr_url, page_text, words);

    for(auto ele : test_urls){
        curr_url = ele;
        parse(curr_url, page_text, words);
        std::ifstream txt1(page_text.c_str());
        if(txt1.is_open()){
            std::string str, pos;
            char ch(' ');
            bool start = false;

            txt1 >> std::noskipws;
            while(txt1 >> ch){
                if(ch == '<'){
                    while((txt1 >> ch) && ch != '>')
                        pos += ch;
                    pos += ch;
                    if(pos.find("/body>") != std::string::npos)
                        start = false;
                    else if(pos.find("body>") != std::string::npos){
                        start = true;
                    }
                    if(start && pos.find("a href=") != std::string::npos){
                            pos = pos.substr(pos.find("\"") + 1, pos.size() - pos.find("\"") - 3);
                            pos = resolve_url(curr_url, pos);
                            CPPUNIT_ASSERT(urls.at(pos) == 't');
                            //std::cout << "pos = " << pos << std::endl; // keep for debugging
                    }
                    pos = "";
                }
            }
        }
    }
}

void ubc_hash_test::get_page_test()
{
    curr_url = "http://www.bobateahouse.net";
    CPPUNIT_ASSERT(!get_page(curr_url, page_text, words));
}

void ubc_hash_test::has_websuffix_test()
{
    std::size_t pg_pos = 0;
    std::string html, htm, shtml, cgi, jsp, asp, aspx, php, pl, cfm;
    html = "http://www.url.html ";
    htm = "http://www.url.htm ";
    shtml = "http://www.url.shtml ";
    cgi = "http://www.url.cgi ";
    jsp = "http://url.jsp ";
    asp = "file://url.asp ";
    aspx  = "file://url.aspx ";
    php = "file://url.php ";
    pl = "file://url.pl ";
    cfm = "file://url.cfm ";

    CPPUNIT_ASSERT(has_websuffix(html, pg_pos = html.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(htm, pg_pos = htm.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(shtml, pg_pos = shtml.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(cgi, pg_pos = cgi.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(jsp, pg_pos = jsp.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(asp, pg_pos = asp.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(aspx, pg_pos = aspx.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(php, pg_pos = php.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(pl, pg_pos = pl.find_last_of("/")));
    CPPUNIT_ASSERT(has_websuffix(cfm, pg_pos = cfm.find_last_of("/")));
}

void ubc_hash_test::has_webprefix_test()
{
    std::string str1("http://www.had_websuffix.com");
    std::string str2("file:///Users/had_websuffix.html");
    std::string str3("www.has_webprefix.com");

    CPPUNIT_ASSERT(has_webprefix(str1));
    CPPUNIT_ASSERT(has_webprefix(str2));
    CPPUNIT_ASSERT(!has_webprefix(str3));
}

void ubc_hash_test::in_scope_test()
{
    std::string home("http://www.macys.com");
    std::string page1("http://www.macys.com/winter_clothes/boots");
    std::string page2("http://www.yummy.com");

    CPPUNIT_ASSERT(in_scope(home, page1));
    CPPUNIT_ASSERT(!in_scope(home, page2));
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
