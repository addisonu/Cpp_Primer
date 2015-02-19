//Rebuild relative URLs into absolute URLs (concept)

#include <iostream>
#include <string>

std::string resolve_url(std::string url, std::string new_url);

int main()
{
//Test resolve_url function

//URLs to build
    std::string str0, str1, str2, str3, str4, str5, str6, str7, str8;
    str0 = "file:///dir1/dir2/dir3/dir4/dir5/dir6/../../dir7/home.html";
    str1 = "./tp1/tp3/h1.html";
    str2 = "../h2.html";
    str3 = "dir1/dir2/dir3/dir4/./dir7/tp1/tp3/h3.html";
    str4 = "../h4.html";
    str5 = "../tp2/h5.html";
    str6 = "file:///dir1/dir2/dir3/dir4/dir5/dir6/../../dir7/h6.html";
    str7 = "../h6.html";
    str8 = "./tp2/no_title.html";

    std::string start_url[9]{str0, str1, str2, str3, str4, str5, str6, str7, str8};

//variables to hold resolved urls
    std::string abs_url = start_url[0];;

    for(unsigned i = 1; i != 9; ++i){

//Homepage URL or initial entry URL should be absolute URL
            abs_url = resolve_url(abs_url, start_url[i]);
            std::cout << abs_url << std::endl;
    }
    return 0;
}

std::string resolve_url(std::string url, std::string new_url)
{
            std::string tmp_url, tmp_new_url, final_url;
            if(new_url.find(".") == 0){

//Search for the patterns "./", "../", and "/" at the new_url beginning
                    if(new_url.find("./") == 0){
                        tmp_new_url = new_url.substr(new_url.find("/"));
                        tmp_url = url.substr(0, url.find_last_of("/"));
                        final_url = (tmp_url + tmp_new_url);
                    }
                    else if(new_url.find("../" == 0)){
                        new_url = new_url.substr(new_url.find("/"));
                        url = url.substr(0, url.find_last_of("/"));
                        url = url.substr(0, url.find_last_of("/"));

                        while(new_url.find("../") == 0){
                            new_url = new_url.substr(new_url.find("/"));
                            url = url.substr(0, url.find_last_of("/"));
                        }
                        final_url = url + new_url;
                }
            }
            else if(new_url.find("file:") == std::string::npos && new_url.find("http://") == std::string::npos){

//Search for position to concatenate url and new_url
                std::string overlap = new_url.substr(0, new_url.find_last_of("/"));
                std::size_t start_pos;
                bool complete = false;
                while(!complete && overlap.size() > 0){
                    start_pos = url.find(overlap);
                    if(start_pos != std::string::npos){
                        complete = true;
                    }
                    else{
                        if(overlap.find_last_of("/") == std::string::npos){
                            start_pos = url.size() - 1;
                            complete = true;
                        }
                        else
                            overlap = overlap.substr(0, overlap.find_last_of("/"));
                    }
                }
//Build absolute url
                final_url = url.substr(0, start_pos) + new_url;
            }
            else{
                final_url = new_url;
            }
//Remove any extra "./" and "../" combinations
            std::size_t curr(0), par(0), curr_len(2), par_len(2);
            std::string tmp, beg, end;

            while((curr = final_url.find("/./")) != std::string::npos || (par = final_url.find("../")) != std::string::npos){
                if(curr != std::string::npos){
                    tmp = final_url.substr(0, curr) + final_url.substr(curr + curr_len);
                    final_url = tmp;
                }
                else if(par != std::string::npos){
                    beg = final_url.substr(0, par - 1);
                    tmp = beg.substr(0, beg.find_last_of("/")) + final_url.substr(par + par_len);
                    final_url = tmp;
                }
            }
                return final_url;
}
