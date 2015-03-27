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

    Word& operator[](const std::string &str)
    {
        Word non;
        return find_word(str, non);
    }

     Word& find_word(const std::string &str, Word &non)
    {
        for(Word &obj : index){
            if(obj.get_word() == str){
                return obj;
            }
        }
        return non;
    }

    void add(Word obj)
    {
        Word non, &tmp_word = find_word(obj.get_word(), non);
        if(!tmp_word.get_word().empty()){
            tmp_word += obj;
        }
        else{
            index.push_back(obj);
        }
    }

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
    friend std::ostream& operator<<(std::ostream &out, const Indexer obj);
};
    std::ostream& operator<<(std::ostream &out, const Indexer obj);
#endif
