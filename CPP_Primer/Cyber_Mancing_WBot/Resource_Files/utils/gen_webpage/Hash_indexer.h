//DATE : 03/18/15
//FILE : Hash_indexer.h
//DESC : Data structure built with an array, relying on a hash function, and operations for indexing words

#ifndef HASH_INDEXER_H
#define HASH_INDEXER_H

#include <cstdlib>
#include <iostream>
#include <new>
#include <string>
#include <sstream>
#include "node2.h"
#include "Word.h"

const std::size_t INDEXER_SIZE = 676; // 2^26 i.e. every two letter combination in English alphabet
const unsigned ALPHA_SIZE = 26; // number of letters in English alphabet

class Hash_indexer{

public:

// CONSTRUCTORS AND DESTRUCTOR //
    Hash_indexer();
    ~Hash_indexer();

// MODIFICATION MEMBER FUNCTIONS //
    void set_word(Word arg_word);
    Word get_word();
    std::size_t get_size(std::string list_indx);
    void set_size(std::size_t val);
    Word& find_word(std::string str, Word &non);
    node<Word>* find_word(std::string str);
    void add(Word arg_word);

// CONSTANT MEMBER FUNCTIONS //

private:

// DATA MEMBERS //
    node<Word>* index[INDEXER_SIZE]; //array of linked lists of Words

// AUXILARY MEMBER FUNCTIONS //
    std::size_t hash_word(std::string word) const;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const Hash_indexer &obj);
};
    std::ostream& operator<<(std::ostream &out, const Hash_indexer &obj);

#endif
