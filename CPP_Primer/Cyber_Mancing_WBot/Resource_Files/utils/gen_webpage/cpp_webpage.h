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

//PRECONDITIONS : N/A
//POSTCONDITIONS : string formatted as HTML title tag is returned
    std::string title(std::string label);

//PRECONDITIONS : para must be fstream connected to a file
//POSTCONDITIONS : string is converted to HTML paragraph and stored in file connected to para
    void paragraph(std::fstream &para, std::string str);

//PRECONDITIONS : N/A
//POSTCONDITIONS : string formatted as HTML image source tag with link to URL is returned
    std::string image(std::string URL);

//PRECONDITIONS : N/A
//POSTCONDITIONS : string formatted as HTML link to URL is returned
    std::string link(std::string URL, std::string label = "");

//PRECONDITIONS : N/A
//POSTCONDITIONS : string formatted as HTML heading tag is returned
    std::string heading(unsigned level, std::string label);
    std::string get_result() { return result; }

private:

// DATA MEMBERS //
    static std::fstream fnull;
    std::string result;
};
#endif
