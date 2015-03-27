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
#include "cpp_webpage.h"

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

// PRECONDITIONS : N/A
// POSTCONDITIONS : A pointer to the Word object containing str is return if it exists
    node<Word>* find_word(std::string str);

// PRECONDITIONS : word in arg_word must have at least one letter, file of stop words must exist, currently at ="../../stop_words.txt", will change to accept as argument
// POSTCONDITIONS : if word is not a stop word, it will have been added to structure or url will have been added and count incremented
    void add(Word arg_word);

// PRECONDITIONS : Directory "webpages_hash/" must exist.
// POSTCONDITIONS : Webpage has been generated for each word in index datamember and stored in "webpages_hash/"
    void gen_webpage();

// CONSTANT MEMBER FUNCTIONS //

private:

// DATA MEMBERS //
    node<Word>* index[INDEXER_SIZE]; //array of linked lists of Words

// AUXILARY MEMBER FUNCTIONS //

// PRECONDITION : word[0] and word[1] are alpha
// POSTCONDITION : position of correct head node for word in index is returned
    std::size_t hash_word(std::string word) const;

// FRIENDS //

// PRECONDITION : N/A
// POSTCONDITION : Each word in index is written on STDOUT delimeted by newlines
    friend std::ostream& operator<<(std::ostream &out, const Hash_indexer &obj);
};
    std::ostream& operator<<(std::ostream &out, const Hash_indexer &obj);

#endif
