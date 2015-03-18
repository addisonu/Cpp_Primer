//DATE : 03/17/15
//FILE : Indexer.h
//DESC : Data structure built with a set and operations for indexing words

/*BUGS :
 * appropriate return value for find_word() if it's not there, maybe return bool and word through arg reference
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

    void gen_indxpg()
    {
        std::fstream fs;
        for(Word page : index){
            Cpp_webpage gen(page.get_word(), "Index of " + page.get_word(), 1, fs, page.to_string());
            std::cout << std::endl << std::endl;
        }
    }
private :

// DATA MEMBERS //
    std::vector<Word> index;
};

#endif

