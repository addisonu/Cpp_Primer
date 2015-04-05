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
    Word(std::string arg_word) : word(arg_word)
    {
// Change word to lower case
        lower_word(word);
    }
    Word(std::string arg_word, unsigned arg_count, std::string arg_url) : word(arg_word), count(arg_count), url(arg_url)
    {
// Change word to lower case
        lower_word(word);

// Create variables to format url data member
        size_t pos(0);

// If there are " " change each one to a "\n"
        if((pos = url.find(" ", pos)) != std::string::npos){
            while((pos = url.find(" ", pos)) != std::string::npos){
                url.replace(pos, 1, "\n");
            }
        }
// If arg_url was not empty, append "\n" to url
        if(url.size())
            url += "\n";
    }

// OTHER MEMBER FUNCTIONS //
    std::string get_word() const { return word; }

    void set_word(std::string arg_word) { word = arg_word; lower_word(word); }

    unsigned get_count() { return count; }

    void set_count(unsigned arg_count) { count = arg_count; }

    std::string get_url() { return url; }

//PRECONDITIONS : N/A
//POSTCONDITIONS : arg_url is added to url data member and count is incremented
    void add_url(std::string arg_url)
    {
// If arg_url is a new URL add it to the Word and increment count
        if(url.find(arg_url) == std::string::npos){
            url += arg_url + "\n"; ++count;
        }
// If arg_url is alread listed on url, increment Word frequency without adding arg_url
        else
            ++count;
    }

    bool empty() { return !word.size(); }

//PRECONDITIONS : N/A
//POSTCONDITIONS : string of Word object's data member names and values is returned
    std::string to_string()
    {
        std::stringstream str;
        str << "word:" << word << "\n" << "count:" << count << "\n" << "URLs:" << "\n" << url;

        return str.str();
    }

//PRECONDITIONS : N/A
//POSTCONDITIONS : lhs Word object is updated with incremented frequency and additional URL if rhs URL isn't already contained
    Word operator+=(const Word rhs)
    {
// Check if rhs and lhs hold the same word
        if(word == rhs.word){
            std::string tmp_url;

// Separate rhs.url into individual URLs to avoid adding duplicate URLs to url
            for(const auto ch : rhs.url){
                if(ch != '\n')
                    tmp_url += ch;
                else{

// add_url will check if tmp_url is already listed in url
                    add_url(tmp_url);
                    tmp_url = "";
                }
            }
        }
        else
            std::cout << "Error : Incompatible word objects." << std::endl;
        return *this;
    }

//PRECONDITIONS : N/A
//POSTCONDITIONS : str with all letters as lowercase is returned
    void lower_word(std::string &str)
    {
        for(auto &ch : str)
            ch = tolower(ch);
    }

//PRECONDITIONS : stop_file must refer to file with stop words delimited by newlines
//POSTCONDITIONS : true is return if word is a word in stop_file, false otherwise
    bool is_stopword(std::string stop_file, std::string word)
    {
        std::string stop_word;
// Add and comment following lines to compile Word_test.cpp with clang++ because ifstream will only take string literal or array
        std::ifstream ifs("../../stop_words.txt");
        //std::ifstream ifs(stop_file);
        if(ifs.is_open()){

// Read each line from stop_file into stop_word and compare to word
            while(std::getline(ifs, stop_word)){
                if(stop_word == word)
                    return true;
            }
        }
        return false;
    }

// FRIENDS //

//PRECONDITIONS : N/A
//POSTCONDITIONS : Each data member of Word is written to STDOUT delimited by newlines
    friend std::ostream& operator<<(std::ostream& out, const Word obj);

private :

// DATA MEMBERS //
    std::string word;
    unsigned count = 0;
    std::string url;
};
    std::ostream& operator<<(std::ostream& out, const Word obj);
#endif
