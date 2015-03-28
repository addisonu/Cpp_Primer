//Implementation of Cpp_webpage class
/* BUGS :
 * change paragraph for when an fstream is passed to the function to add <br> to generated page
 * no way to write generated page to files - status [fixed] - problem [constructor takes fstream or string as source of words to index, require file stream to write to file and string as word to generate page for]
 *
 */

#include "cpp_webpage.h"

// CONSTUCTORS //

Cpp_webpage::Cpp_webpage()
{
// Specify html document type
    std::cout << "<!DOCTYPE html>" << std::endl;

// Start html doc
    std::cout << "<html>" << std::endl;

// Start html head
    std::cout << "<head>" << std::endl;

// End html head
    std::cout << "</head>" << std::endl;

// Start html body
    std::cout << "<body>" << std::endl;

// End html body
    std::cout << "</body>" << std::endl;

// End html doc
    std::cout << "</html>";
}

Cpp_webpage::Cpp_webpage(std::string tle, std::string header, unsigned lev, std::fstream &fpara, const std::string &spara)
{
// Specify html document type
    fpara << "<!DOCTYPE html>" << std::endl;

// Start html doc
    fpara << "<html>" << std::endl;

// Start html head
    fpara << "<head>" << std::endl;

// Print title
    fpara << title(tle) << std::endl;

// End html head
    fpara << "</head>" << std::endl;

// Start html body
    fpara << "<body>" << std::endl;

// Print header
    fpara << heading(lev, header) << std::endl;

// Print paragraph
    paragraph(fpara, spara);

// End html body
    fpara << "</body>" << std::endl;

// End html doc
    fpara << "</html>";
}

// MEMBER FUNCTIONS //

std::string Cpp_webpage::title(std::string label)
{
// Reset result
    result = "";

// Open html title tags, print label, close tags
    return result ="<title>" + label + "</title>\n";
}

void Cpp_webpage::paragraph(std::fstream &para, std::string str)
{
// Reset result
    result = "";

// If string is passed, copy argument string into result
    std::string line;

// Check if str is empty, if not print each word on separate line
    if(str.size()){
        for(auto ch : str){
            if(isspace(ch))
                result += "<br>";
            else
                result += ch;
        }
    }
// Wrap result in html paragraph tags
    para << "<p>" << result << "</p>";
}

std::string Cpp_webpage::image(std::string URL)
{
// Reset result
    result = "";

// Open html image tag, add URL, close tags
    return result = "<img src=\"" + URL + "\" />\n";
}

std::string Cpp_webpage::link(std::string URL, std::string label)
{
// Reset result
    result = "";

// Open html link tag, add URL, close tags
    if(label != "")
        return result = "<a href=\"" + URL + "\"></a>\n";

    else
        return result = "<a href=\"" + URL + "\">" + label + "</a>\n";
}

std::string Cpp_webpage::heading(unsigned level, std::string label)
{
// Reset result
    result = "";

// Convert level to string
    std::string num = std::to_string(level);

// Open html heading tags of size level, print heading, close tags
    return result = "<h" + num + ">" + label + "</h" + num + ">\n";
}
