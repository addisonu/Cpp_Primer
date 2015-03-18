//Implementation of Cpp_webpage class
/* BUGS :
 * change paragraph for when an fstream is passed to the function to add <br> to generated page
 *
 */

#include "cpp_webpage.h"

// CONSTUCTORS //

Cpp_webpage::Cpp_webpage()
{
//Specify html document type
    std::cout << "<!DOCTYPE html>" << std::endl;

//Start html doc
    std::cout << "<html>" << std::endl;

//Start html head
    std::cout << "<head>" << std::endl;

//End html head
    std::cout << "</head>" << std::endl;

//Start html body
    std::cout << "<body>" << std::endl;

//End html body
    std::cout << "</body>" << std::endl;

//End html doc
    std::cout << "</html>";
}

Cpp_webpage::Cpp_webpage(std::string tle, std::string header, unsigned lev, std::fstream &fpara, std::string spara)
{
//Specify html document type
    std::cout << "<!DOCTYPE html>" << std::endl;

//Start html doc
    std::cout << "<html>" << std::endl;

//Start html head
    std::cout << "<head>" << std::endl;

//Print title
    std::cout << title(tle) << std::endl;

//End html head
    std::cout << "</head>" << std::endl;

//Start html body
    std::cout << "<body>" << std::endl;

//Print header
    std::cout << heading(lev, header) << std::endl;

//Print paragraph
    std::cout << paragraph(fpara, spara) << std::endl;

//End html body
    std::cout << "</body>" << std::endl;

//End html doc
    std::cout << "</html>";
}

// MEMBER FUNCTIONS //

std::string Cpp_webpage::title(std::string label)
{
//Reset result
    result = "";

//Open html title tags, print label, close tags
    return result ="<title>" + label + "</title>\n";
}

std::string Cpp_webpage::paragraph(std::fstream &para, std::string str)
{
//Reset result
    result = "";

//If string is passed, copy argument string into result
    std::string line;
    if(str.size()){
        for(auto ch : str){
            if(isspace(ch))
                result += "<br>";
            else
                result += ch;
        }
    }

//If fstream is passed, read line form fstream into result
    else if(para >> line){
        std::cout << "line : " << line << std::endl;
        result += line;
        while(para >> line){
            std::cout << "in while loop" << std::endl;
            result += "<br>" + line;
        }
    }
//Return result wrapped in html paragraph tags
    return result = "<p>" + result + "</p>";
}

std::string Cpp_webpage::image(std::string URL)
{
//Reset result
    result = "";

//Open html image tag, add URL, close tags
    return result = "<img src=\"" + URL + "\" />\n";
}

std::string Cpp_webpage::link(std::string URL, std::string label)
{
//Reset result
    result = "";

//Open html link tag, add URL, close tags
    if(label != "")
        return result = "<a href=\"" + URL + "\"></a>\n";

    else
        return result = "<a href=\"" + URL + "\">" + label+ "</a>\n";
}

std::string Cpp_webpage::heading(unsigned level, std::string label)
{
//Reset result
    result = "";

//Convert level to string
    std::string num = std::to_string(level);

//Open html heading tags of size level, print heading, close tags
    return result = "<h" + num + ">" + label + "</h" + num + ">\n";
}
