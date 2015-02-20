//Find all URLs on website (concept)

/*LEFT OFF:
 * unbreaking ubc.cpp, boba house return 1 url, problems after adding in_scope function to limit returned urls to those prefixed with original page location
 * consider removing has_webprefix function and replacing with working in_scope function
 */

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <sstream>
#include <queue>
#include <map>
#include "web/URLConnection.h"
#include "../../dir1/resolve_url.cpp"

std::set<std::string> parse(std::string url, std::string &page_text);
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text);
void get_page(std::string url, std::string page_text);
bool has_websuffix(std::string str, std::size_t pg_pos);
bool has_webprefix(std::string str);
bool in_scope(std::string home_url, std::string new_url);
std::set<std::string> find_url(std::fstream fs);

int main()
{
//Resources to download and parse page
    std::string url("website");
    std::string page_text = "test_download.txt";
    std::map<std::string, char> urls = page_links(url, page_text);

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

void get_page(std::string url, std::string page_text)
{
// Download page //
//Write downloaded page to argument file
    std::fstream fs(page_text, std::fstream::binary | std::fstream::in | std::fstream::out);
    fs << std::noskipws;
    InputStream *doc;

    doc = URLConnection::Open(url);

    while(!doc->IsDone()){
        char c = doc->Read();
        fs << c;
    }
    fs.close();
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

std::set<std::string> parse(std::string url, std::string &page_text)
{
// Download page //
    get_page(url, page_text);

// Isolate URLs //
//Create variables to read text
    std::fstream fs(page_text, std::fstream::binary | std::fstream::in | std::fstream::out | std::fstream::trunc);
    std::string str;
    unsigned char c(' ');
    unsigned url_cnt(0);
    std::set<std::string> found_links;

//Parse text to isolate tags
    if(fs.is_open()){
        while(fs >> c){
            if(c == '<'){
                fs >> c;
                while(c != '>'){
                    str += c;
                    fs >> c;
                }
                std::size_t spos(0), epos(0), pg_pos(0);
                if(!str.empty() && (spos = str.find("href")) < std::string::npos){

                    spos = str.find("\"", spos);
                    epos = str.find("\"", spos + 1);
                    str = str.substr(spos, epos - spos + 1);

                    if(str.find("/") != std::string::npos){
                        pg_pos = str.find_last_of("/");
                    }

                    if(has_websuffix(str, pg_pos)){

//Remove quotes from str
                        str = str.substr(1, str.size() - 2);
                //debugging
                        std::cout << "str = " << str << std::endl;
                        found_links.insert(str);
                        ++url_cnt;
                    }
                }
                str = "";
            }
            else;
        }
    }
    return found_links;
}

// Do bfs of website //
std::map<std::string, char> page_links(std::string curr_url, std::string &page_text)
{
//Hold all links found on page of processed url
    std::set<std::string> found_links;

//Hold all urls to be processed
    std::queue<std::string> process_links;

//Track process status of url
    std::map<std::string, char> urls;

//Prepare to process the first url before entering loop
    curr_url = resolve_url(curr_url, curr_url);
    urls.insert(std::pair<std::string, char>(curr_url, 't'));
    process_links.push(curr_url);
    std::string abs_url(curr_url);

//Process urls until no new ones remain
    while(!process_links.empty()){
        found_links = parse(process_links.front(), page_text);

//Transfer elements from found_links to URLs and process_links
        std::string abs_path;
        for(std::string link : found_links){
            abs_path = resolve_url(process_links.front(), link);
        //debugging
            std::cout << "abs_path = " << abs_path << std::endl;

            if(has_webprefix(abs_path)/* && in_scope(curr_url, abs_path)*/){
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
