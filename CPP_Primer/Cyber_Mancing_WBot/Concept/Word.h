//DATE : 03/16/15
//FILE : Word.h
//DESC : Word class will create objects that can hold a given word, word frequency, and all URLs where word is found

#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
#include <iostream>
#include <set>

class Word{

public :

// MEMBER FUNCTIONS //
// CONSTRUCTORS //
    Word() { }
    Word(std::string arg_word) : word(arg_word) { }
    Word(std::string arg_word, unsigned arg_count, std::string arg_url) : word(arg_word), count(arg_count), url(arg_url) { }

// OTHER MEMBER FUNCTIONS //
    std::string get_word() { return word; }

    void set_word(std::string arg_word) { word = arg_word; }

    unsigned get_count() { return count; }

    void set_count(unsigned arg_count) { count = arg_count; }

    std::string get_url() { return url; }

    void add_url(std::string arg_url){ url += " " + arg_url; ++count; }

    bool empty() { return word.size(); }

    std::string to_string()
    {
        std::stringstream str;
        str << word << " " << count << " " << url;
        return str.str();
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
            << "URLs : " << obj.url;
        return out;
    }
#endif
