//DATE : 03/17/15
//FILE : Indexer.h
//DESC : Data structure built with a set and operations for indexing words
//VERSION : 1

/*BUGS :
 * appropriate return value for find_word() if it's not there, maybe return bool and word through arg reference
 * check if any object is defined in file, duplicate will occur during linking
 * duplicate words on the same page aren't added, should be and increment count and not concatenated url - status [fixed] - problem [needed to add else branch to condition, if false increment count]
 */


#ifndef INDEXER_H
#define INDEXER_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <sstream>
#include <fstream>
#include "Word.h"
#include "cpp_webpage.h"

class Indexer{

public :

// MEMBER FUNCTIONS //
// CONSTRUCTORS //
    Indexer() { }

// OTHER MEMBER FUNCITONS //
    void set_word(const std::string &str, const Word arg_word)
    {
        Word non, &tmp_word = find_word(str, non);
        if(!tmp_word.get_word().empty())
            tmp_word = arg_word;
    }

// PRECONDITIONS : N/A
// POSTCONDITIONS : If Word objective with word equal to str is in index, a reference to the Word will be returned
    Word& operator[](const std::string &str)
    {
        Word non;
        return find_word(str, non);
    }

// PRECONDITIONS : N/A
// POSTCONDITIONS : If Word objective with word equal to str is in index, a reference to the Word will be returned
     Word& find_word(const std::string &str, Word &non)
    {
        for(Word &obj : index){
            if(obj.get_word() == str){
                return obj;
            }
        }
        return non;
    }

// PRECONDITIONS : file "../../stop_words.txt" must exist.
// POSTCONDITIONS : If the Word object's word isn't a stop word, it is added to index
     void add(Word obj)
    {
        Word non, &tmp_word = find_word(obj.get_word(), non);
        if(!tmp_word.get_word().empty()){
            tmp_word += obj;
        }
        else{
            std::string stop_file = "../../stop_words.txt";
            if(!(obj.is_stopword(stop_file, obj.get_word())))
                index.push_back(obj);
        }
    }

// PRECONDITIONS : File "webpages_idx/" must exist.
// POSTCONDITIONS : Webpage for each Word in index is generated and stored in "webpages_idx/"
    void gen_webpage()
   {
    unsigned header_lv = 1;

//Loop through Hash_indexer
    for(auto ele : index){

//Create and initialize fstream with file to generate webpage in
        std::string path = "webpages_idx/" + ele.get_word() + ".html";
        std::fstream txt("webpages_idx/" + ele.get_word() + ".html", std::fstream::in | std::fstream::out| std::fstream::trunc);

//Call class to generate webpage
        Cpp_webpage page("Index for : " + ele.get_word(), "Index for : " + ele.get_word(), header_lv, txt, ele.to_string());
        txt.close();
    }
}

private :

// DATA MEMBERS //
    std::vector<Word> index;

// FRIENDS //

// PRECONDITIONS : N/A
// POSTCONDITIONS : Each word in index is written to STDOUT delimited by newlines
    friend std::ostream& operator<<(std::ostream &out, const Indexer obj);
};
    std::ostream& operator<<(std::ostream &out, const Indexer obj);
#endif
