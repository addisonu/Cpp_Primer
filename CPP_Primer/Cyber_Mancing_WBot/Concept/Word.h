//DATE : 03/16/15
//FILE : Word.h
//DESC : Word class will create objects that can hold a given word, word frequency, and all URLs where word is found

#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <algorithm>

class Word{

public :

// MEMBER FUNCTIONS //
// CONSTRUCTORS //
    Word() { }
    Word(std::string arg_word) : word(arg_word) { }
    Word(std::string arg_word, unsigned arg_count, std::string arg_url) : word(arg_word), count(arg_count), url(arg_url)
    {
        size_t pos(0);
        if((pos = url.find(" ", pos)) != std::string::npos){
            while((pos = url.find(" ", pos)) != std::string::npos){
                url.replace(pos, 1, "\n");
            }
        }
        if(url.size())
            url += "\n";
    }

// OTHER MEMBER FUNCTIONS //
    std::string get_word() const { return word; }

    void set_word(std::string arg_word) { word = arg_word; }

    unsigned get_count() { return count; }

    void set_count(unsigned arg_count) { count = arg_count; }

    std::string get_url() { return url; }

    void add_url(std::string arg_url){ url += arg_url + "\n"; ++count; }

    bool empty() { return word.size(); }

    std::string to_string()
    {
        std::stringstream str;
        str << "word:" << word << "\n" << "count:" << count << "\n" << "URLs:" << "\n" << url;

        return str.str();
    }

    Word operator+=(const Word rhs)
    {
        std::string tmp_str;
        std::stringstream sstr;

        while(sstr << rhs.url){
            std::string tmp_str;
            sstr >> tmp_str;
            add_url(tmp_str);
        }
        return *this;
    }
   // FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, const Word obj);

private :

// DATA MEMBERS //
    std::string word;
    unsigned count = 0;
    std::string url;
};

    std::ostream& operator<<(std::ostream& out, const Word obj)
    {
        std::cout << "word : " << obj.word << "\n"
            << "count : " << obj.count << "\n"
            << "URLs : " << "\n" << obj.url;

        return out;
    }
#endif
