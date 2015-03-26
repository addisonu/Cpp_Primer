//Class to generate simple webpages

#ifndef CPP_WEBPAGE_H
#define CPP_WEBPAGE_H

#include <iostream>
#include <string>
#include <fstream>

class Cpp_webpage{

public:


// CONSTUCTORS //
    Cpp_webpage();
    Cpp_webpage(std::string title, std::string header, unsigned lev, std::fstream &fpara = fnull, const std::string &spara = "");

// MEMBER FUNCTIONS //
    std::string title(std::string label);
    void paragraph(std::fstream &para, std::string str);
    void line_break() { std::cout << std::endl; }
    std::string image(std::string URL);
    std::string link(std::string URL, std::string label = "");
    std::string heading(unsigned level, std::string label);
private:

// DATA MEMBERS //
    static std::fstream fnull;
    std::string result;
};
#endif
