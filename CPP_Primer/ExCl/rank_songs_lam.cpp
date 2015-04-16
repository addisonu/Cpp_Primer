// Rank songs using Zip's law and print the m most played of the n album songs. Alternate implementaion using a lambda to sort songs in album.

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <utility>

int main(int argc, char **argv)
{
// Get number of songs in album and number of most played songs to display
    unsigned song_num(0), top_num(0);
    std::string input;
    std::cout << "Enter the number of songs on the album.\n";
    std::getline(std::cin, input);
    song_num = atoi(input.c_str());

    std::cout << "Enter the number of top songs that should be returned.\n";
    std::getline(std::cin, input);
    top_num = atoi(input.c_str());

// Each element of album holds number of plays and song name
    std::vector<std::pair<double, std::string>> album;
    std::pair<double, std::string> song;

// Get each album elements from user
    for(unsigned i = song_num; i > 0; --i){
        std::cout << "Enter the next song.\n";
        std::getline(std::cin, input);
        std::stringstream ss(input);
        ss >> song.first;
        song.first /= i;
        ss >> song.second;
        album.push_back(song);
    }
// Sort songs using library sort function and lambda
    if(top_num && album.size()){
        std::sort(album.begin(), album.end(), [ ](std::pair<double, std::string> p1, std::pair<double, std::string> p2) -> bool { return p1.first > p2.first; });
    }

// Print most played songs
    for(auto i = album.begin(); i != album.begin() + top_num; ++i)
        std::cout << i->second << std::endl;

    return 0;
}
