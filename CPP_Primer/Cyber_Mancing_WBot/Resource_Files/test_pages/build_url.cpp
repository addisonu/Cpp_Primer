//Rebuild relative URLs into absolute URLs (concept)

#include <iostream>
#include <string>

std::string resolve_url(std::string url, std::string new_url)
{
            std::string tmp_url, tmp_new_url, final_url;
            if(new_url.find(".") == 0){

// Search for the patterns "./", "../", and "/" at the new_url beginning
// Resolve each URL according path rules
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
// If path is relative but doesn't start with '."
            else if(new_url.find("file:") == std::string::npos && new_url.find("http://") == std::string::npos){

// Check if url and new_url are equal
                if(url.find(new_url) != std::string::npos){
                    url = new_url;
                }
                else{

// If url doesn't begin with '/' add it
                if(new_url[0] != '/')
                    new_url = "/" + new_url;

// Search for position to concatenate url and new_url
                std::string overlap = new_url.substr(0, new_url.find_last_of("/"));
                std::size_t start_pos = (url.size() > 7) ? url.find_first_of("/", 7) : url.size();
                bool complete = false;

// Check if entire home url must be prepended to new_url
                if(overlap.size() == 0){
                    ;
                }
// If not, remove the redundant parts of the path
                else{
                    while(!complete && overlap.size() > 0){
                        start_pos = url.find(overlap);
                        if(start_pos != std::string::npos){
                            complete = true;
                        }
                        else{
                            if(overlap.find_last_of("/") == std::string::npos){
                                start_pos = url.size() - 2;
                                complete = true;
                            }
                            else
                                overlap = overlap.substr(0, overlap.find_last_of("/"));
                        }
                    }
                }
//Build absolute url
                final_url = url.substr(0, start_pos) + new_url;
                }
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
//Remove parameters
            std::size_t params = final_url.find("?");
            if(params != std::string::npos)
                final_url = final_url.substr(0, params);
                return final_url;
}
