// DESC : Search for urls and index words using Hash_indexer data structure
// LEFT OFF //
/*
 * adding code to generate webpage
 */

// BUGS //
/*
 * relative URLs with only final part of path are duplicating last part of path which produces incorrect URLs - status [fixed] - prblem [used string function find_last_of which will search all char up to arg position, instead of find_first_of which will search all char at and after arg position]
 * file not being downloaded #1 - status [fixed] - problem [fstream opened in trunc mode for parse() function]
 * file not being downloaded #2 - status [fixed] - problem [test_download.txt file must exist]
 * urls with only one '/' are discarded, and others are returned from resolve_url() with extra '/' at concatenation point - status [fixed] - problem [handle the separate case where there is no overlap and entire home URL must be concatenated with relative URL]
 * program will terminate if page can't be downloaded - status [fixed] - problem [added exception handling code in try catch block to catch CS240Exception, bad URLs are now skipped]
 * no objects of type Word are being added to var words - status [fixed] - problem [some words begin with a nonalpha char and can't be hashed, hash_word() changed and condition checks string size]
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
#include "../../test_pages/build_url.cpp"
#include "Hash_indexer.h"
#include "Word.h"

std::set<std::string> parse(std::string url, std::string &page_text, Hash_indexer &words);
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text, Hash_indexer &words);
int get_page(std::string url, std::string &page_text, Hash_indexer &words);
bool has_websuffix(std::string str, std::size_t pg_pos);
bool has_webprefix(std::string str);
bool in_scope(std::string home_url, std::string new_url);
std::set<std::string> find_url(std::fstream fs);

int main()
{
//Resources to download and parse page
//!!ADD PROPER URL BEFORE TESTING!!
    std::string url("http://www.bobateahouse.net");
    std::string page_text = "test_download.txt";
    Hash_indexer words;
    std::map<std::string, char> urls = page_links(url, page_text, words);

    std::cout << "There are " << urls.size() << " urls. Oh yeah!" << std::endl;

    for(std::pair<std::string, char> link : urls){
        std::cout << link.first << std::endl;
    }
    words.gen_webpage();
    return 0;
}

// PRECONDITIONS : home_url is the original URL passed to program in absolute path form
// POSTCONDITIONS : return true if new_url is part website, false otherwise
bool in_scope(std::string home_url, std::string new_url)
{
    std::string location = home_url.substr(0, home_url.find("/", 7));
    return new_url.find(location) == 0;
}

// PRECONDITIONS : str has no spaces
// POSTCONDITIONS : return true if first 5 - 7 characters represent beginning of proper URL
bool has_webprefix(std::string str)
{
//Simplify string beginning conditions to limit URLs recognized as links
    return (str.substr(0, 7) == "http://") || (str.substr(0, 5) == "file:");
}

// PRECONDITIONS : url is the main URL of website and is the absolute path
// POSTCONDITIONS : Webpage is downloaded and stored in a file specified by page_text
int get_page(std::string url, std::string &page_text, Hash_indexer &words)
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

// PRECONDITIONS : pg_pos represents the '/' after http:// or file:// and immediately before the file name in it's absoluted path form
// POSTCONDITIONS : true is returned if the file name has one of the following webpage file extensions, false otherwise
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

// PRECONDITIONS : N/A
// POSTCONDITIONS : Downloaded webpage is parsed and URLs and words are isolated and processed
std::set<std::string> parse(std::string url, std::string &page_text, Hash_indexer &words)
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
    std::string str, tmp_words; // str holds tags and words holds words to be indexed
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
                if((isspace(c) || c == '\n') && !tmp_words.empty()){
                    if(tmp_words.size() && isalpha(tmp_words[0]))
                    words.add(Word(tmp_words, 1, url));
                    tmp_words = "";
                }
                else if(isalpha(c)){
                    tmp_words += c;
                }
            }
        }
    }
    return found_links;
}

// Do bfs of website //
// PRECONDITIONS : N/A
// POSTCONDITIONS : A breadth first search of website starting at curr_url is performed and URLs are processed
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text, Hash_indexer &words)
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
