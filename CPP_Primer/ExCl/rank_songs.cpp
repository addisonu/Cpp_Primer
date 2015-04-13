// Rank songs using Zip's law and print the m most played of the n album songs

#include <iostream>
#include <vector>
#include <list>
#include <sstream>
#include <string>
#include <utility>

int main(int argc, char **argv)
{
    int song_num(0), top_num(0);
    std::string input;
    std::cout << "Enter the number of songs on the album.\n";
    std::getline(std::cin, input);
    song_num = atoi(input.c_str());

    std::cout << "Enter the number of top songs that should be returned.\n";
    std::getline(std::cin, input);
    top_num = atoi(input.c_str());

    std::vector<std::pair<double, std::string>> album;
    std::list<std::pair<double, std::string>> hits;

    std::pair<double, std::string> song;

    for(unsigned i = song_num; i > 0; --i){
        std::cout << "Enter the next song.\n";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> song.first;
        song.first /= i;
        ss >> song.second;
        album.push_back(song);
    }

// Check if new song is one of the top plays
    if(top_num){
        std::pair<double, std::string> max(0, ""), last(0, "");
        for(int i = 0; i != top_num; ++i){
            for(auto ele : album){
                if(i == 0){
                    if(ele.first > max.first)
                        max = ele;
                }
                else{
                    if(ele.first < last.first && ele.first > max.first){
                       max = ele;
                    }
                }
            }
                hits.push_back(max);
                last = max;
                max.first = 0;
        }
    }
    return 0;
}
