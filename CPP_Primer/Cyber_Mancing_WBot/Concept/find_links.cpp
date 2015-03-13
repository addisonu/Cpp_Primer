// LEFT OFF //
/*
 * Writing function to index words on each webpage and creating data structure to hold indexed words
 *
 */

// BUGS //
/*
 * relative URLs with only final part of path are duplicating last part of path which produces incorrect URLs - status [fixed] - prblem [used string function find_last_of which will search all char up to arg position, instead of find_first_of which will search all char at and after arg position]
 * file not being downloaded #1 - status [fixed] - problem [fstream opened in trunc mode for parse() function]
 * file not being downloaded #2 - status [fixed] - problem [test_download.txt file must exist]
 * urls with only one '/' are discarded, and others are returned from resolve_url() with extra '/' at concatenation point - status [fixed] - problem [handle the separate case where there is no overlap and entire home URL must be concatenated with relative URL]
 * program will terminate if page can't be downloaded - status [fixed] - problem [added exception handling code in try catch block to catch CS240Exception, bad URLs are now skipped]
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <queue>
#include <map>
#include "web/URLConnection.h"
#include "web/CS240Exception.h"
#include "../../test_pages/build_url2.cpp"

std::set<std::string> parse(std::string url, std::string &page_text, std::string &words);
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text, std::string &words);
int get_page(std::string url, std::string &page_text, std::string &words);
bool has_websuffix(std::string str, std::size_t pg_pos);
bool has_webprefix(std::string str);
bool in_scope(std::string home_url, std::string new_url);
std::set<std::string> find_url(std::fstream fs);

int main()
{
//Resources to download and parse page

    std::string url("website");
    std::string page_text = "test_download.txt";
    std::map<std::string, char> urls = page_links(url, page_text, words);
    std::string words;

    std::cout << "There are " << urls.size() << " urls. Oh yeah!" << std::endl;

    for(std::pair<std::string, char> link : urls){
        std::cout << link.first << std::endl;
    }
    return 0;
}

bool in_scope(std::string home_url, std::string new_url)
{
    std::string location = home_url.substr(0, home_url.find("/", 7));
    return new_url.find(location) == 0;
}

bool has_webprefix(std::string str)
{
//Simplify string beginning conditions to limit URLs recognized as links
    return (str.substr(0, 7) == "http://") || (str.substr(0, 5) == "file:");
}

int get_page(std::string url, std::string &page_text, std::string &words)
{
// Download page //
//Write downloaded page to argument file
    std::fstream fs(page_text, std::fstream::binary | std::fstream::in | std::fstream::out);
    fs << std::noskipws;

    try{
        InputStream *doc;

        doc = URLConnection::Open(url);

        while(!doc->IsDone()){
            char c = doc->Read();
            fs << c;
        }
        fs.close();
        return 0;
    }
    catch(CS240Exception err){
        std::cout << err.GetMessage() << std::endl;
        return -1;
    }
}

bool has_websuffix(std::string str, std::size_t pg_pos)
{
//Simplify string ending conditions to limit URLs recognized as links
    bool end = (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".html") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".htm") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".shtml") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".cgi") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".jsp") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".asp") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".aspx") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".php") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".pl") != std::string::npos)
        || (str.substr(pg_pos, str.length() - pg_pos - 1 ).find(".cfm") != std::string::npos);
    return end;
}

std::set<std::string> parse(std::string url, std::string &page_text, std::string &words)
{
// Download page //

//If page isn't downloaded return an empty set, the calling function will check set size and handle as appropriate
    if(get_page(url, page_text, words)){
        std::set<std::string> empty;
        return empty;
    }

// Isolate URLs //
    std::fstream fs(page_text, std::fstream::binary | std::fstream::in | std::fstream::out);
    std::set<std::string> found_links;

//Parse text to isolate tags
    if(fs.is_open()){

//Create variables to read text
    std::string str, words; // str holds tags and words holds words to be indexed
    unsigned char c(' ');
    unsigned url_cnt(0);
    bool in_body(false);

    fs << std::noskipws;//change default fstream behavior to read white space

        while(fs >> c){

            if(c == '<'){
                fs << std::skipws;
                while(c != '>'){
                    str += c;
                    fs >> c;
                }
                str += c;

//Check for words to index only between body tags
                if(str.find("<body>") != std::string::npos)
                    in_body = true;
                else if(str == "</body>")
                    in_body = false;
//Find links
                std::size_t spos(0), epos(0), pg_pos(0);
                if(!str.empty() && (spos = str.find("ahref")) != std::string::npos){
                    spos = str.find("\"", spos);
                    epos = str.find("\"", spos + 1);
                    str = str.substr(spos, epos - spos + 1);

                    if(str.find("/") != std::string::npos){
                        pg_pos = str.find_last_of("/");
                    }

                    if(has_websuffix(str, pg_pos)){

//Remove quotes from str
                        str = str.substr(1, str.size() - 2);
                        found_links.insert(str);
                    }
                    str = "";
                }
                else
                    str = "";
                fs << std::noskipws;
            }
            else if(!ispunct(c) && in_body){
                if(isspace(c) || c == '\n')
                    c = ' ';
                words += c;
            }
        }
    return found_links;
}

// Do bfs of website //
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text, std::string &words)
{
//Hold all links found on page of processed url
    std::set<std::string> found_links;

//Hold all urls to be processed
    std::queue<std::string> process_links;

//Track process status of url
    std::map<std::string, char> urls;

//Prepare to process the first url before entering loop
//Add code to make sure initial URL contains only location
    curr_url = resolve_url(curr_url, curr_url);
    std::cout << "curr_url = " << curr_url << '\n';
    urls.insert(std::pair<std::string, char>(curr_url, 't'));
    process_links.push(curr_url);
    std::string abs_url(curr_url);

//Process urls until no new ones remain
    while(!process_links.empty()){
        found_links = parse(process_links.front(), page_text, words);

//Check that initial page was downloaded
        if(!found_links.size()){
            if(process_links.front() == curr_url){
                std::cerr << "You have entered an invalid initial URL. The program will now exit." << std::endl;
                return urls;
            }
            else{
                std::cerr << "Invalid URL" << std::endl;
                process_links.pop();
            }
        }

//Transfer elements from found_links to URLs and process_links
        std::string abs_path;
        for(std::string link : found_links){
            abs_path = resolve_url(process_links.front(), link);
                if(in_scope(curr_url, abs_path)){
                urls.insert(std::pair<std::string, char>(abs_path, 'f'));

                if(urls[abs_path] == 'f'){
                    process_links.push(abs_path);
                    urls[abs_path] = 't';
                }
            }
        }

//Remove processed URL from process_links
        process_links.pop();
    }

    return urls;
}
