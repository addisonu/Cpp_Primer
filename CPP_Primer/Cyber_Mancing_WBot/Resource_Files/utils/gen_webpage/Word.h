//DATE : 03/16/15
//FILE : Word.h
//DESC : Word class will create objects that can hold a given word, word frequency, and all URLs where word is found

// LEFT OFF //
/*
 */

// BUGS //
/*
 * duplicate ostream symbol found during linking - status [fixed] - problem [overloaded operator<< function defined in header file]
 * operatro+= function not adding URLs to this - status [fixed] - misuse of stringstream,use += with url data member instead]
 * word can be added multiple times for the same page - status [fixed] - problem [+= add entire URL of right-hand operand without searching if any URLs were duplicates]
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#ifndef WORD_H
#define WORD_H

#include <string>
#include <sstream>
#include <iostream>
#include <set>
#include <fstream>
#include <algorithm>

class Word{

public :

// MEMBER FUNCTIONS //
// CONSTRUCTORS //
    Word() { }
    Word(std::string arg_word) : word(arg_word) { }
    Word(std::string arg_word, unsigned arg_count, std::string arg_url) : word(arg_word), count(arg_count), url(arg_url)
    {
//Change word to lower case
        lower_word(word);
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

    void set_word(std::string arg_word) { word = arg_word; lower_word(word); }

    unsigned get_count() { return count; }

    void set_count(unsigned arg_count) { count = arg_count; }

    std::string get_url() { return url; }

    void add_url(std::string arg_url)
    {
        if(url.find(arg_url) == std::string::npos){
            url += arg_url + "\n"; ++count;
        }
        else
            ++count;
    }

    bool empty() { return word.size(); }

    std::string to_string()
    {
        std::stringstream str;
        str << "word:" << word << "\n" << "count:" << count << "\n" << "URLs:" << "\n" << url;

        return str.str();
    }

    Word operator+=(const Word rhs)
    {
        if(word == rhs.word){
            std::string tmp_url;
            for(const auto ch : rhs.url){
                if(ch != '\n')
                    tmp_url += ch;
                else{
                    add_url(tmp_url);
                    tmp_url = "";
                }
            }
        }
        else
            std::cout << "Error : Incompatible word objects." << std::endl;
        return *this;
    }

    void lower_word(std::string &str)
    {
        for(auto &ch : str)
            ch = tolower(ch);
    }

    bool is_stopword(std::string stop_file, std::string word)
    {
        std::string stop_word;
        std::ifstream ifs(stop_file);

        if(ifs.is_open()){
            while(std::getline(ifs, stop_word)){
                if(stop_word == word)
                    return true;
            }
        }
        return false;
    }

// FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, const Word obj);

private :

// DATA MEMBERS //
    std::string word;
    unsigned count = 0;
    std::string url;
};
    std::ostream& operator<<(std::ostream& out, const Word obj);
#endif
