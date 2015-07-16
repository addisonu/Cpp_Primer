// DATE : 07/15/15
// FILE : APAN:07.15.15.cpp
// DESC : Use filestreams to open, read, and write files

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main()
{
// Create file stream objects
    std::fstream fs0;
    std::fstream fs1("topics.txt");
    std::fstream fs2("topics.txt", std::fstream::in | std::fstream::out | std::fstream::binary);
    std::ifstream ifs;
    std::ofstream ofs;

// Use file stream operations
    std::cout << std::boolalpha;
    std::cout << "fs0.is_open() : " << fs0.is_open() << std::endl;
    std::cout << "fs1.is_open() : " << fs1.is_open() << std::endl;
    if(fs1.is_open()){
        std::cout << "The file will now be closed.\n";
        fs1.close();
        std::cout << "fs1.is_open() : " << fs1.is_open() << std::endl;
    }
    ifs.open("topics.txt", std::fstream::in);
    ofs.open("topics_out.txt", std::fstream::out | std::fstream::trunc);

// Read file
    if(ifs.is_open()){
        std::string line;
        std::vector<std::string> vline;
        while(std::getline(ifs, line) && (vline.size() < 20)){
            vline.push_back(line);
        }
        std::cout << "vline :\n";
        for(auto ln : vline){
            std::cout << ln << std::endl;

// Write file
            if(toupper(ln[0]) == 'A' || toupper(ln[0]) == 'E' || toupper(ln[0]) == 'I' || toupper(ln[0]) == 'O' || toupper(ln[0]) == 'U')
                ofs << ln << '\n' << '\n';
        }
    }
    return 0;
}
