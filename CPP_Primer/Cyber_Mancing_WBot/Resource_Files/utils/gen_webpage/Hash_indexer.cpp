// DATE : 03/18/15
// FILE : Hash_indexer.cpp
// DESC : Implementation of Hash_indexer class

// LEFT OFF //
/*
 * adding gen_webpage code
 * deciding which functions should be removed, changed, added
 */

// BUGS //
/*
 * hash_word only works for strings beginning with two letters - status [not fixed] - problem [needed conditional branch for words length 1 and length > 1]
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#include "Hash_indexer.h"

// CONSTRUCTORS AND DESTRUCTOR //
Hash_indexer::Hash_indexer()
{
    unsigned start = 97; // dec value of 'a' on ASCII table
    std::string dict("uu"); //first element in linked list
    dict[0] = start;
    dict[1] = start - 1;
    unsigned cnt(0);

// Add every two letter combination to a consecutive head node element in index
    for(auto &ele : index){

// if the first and second letters of dict <= z
        if(dict[0] < start + ALPHA_SIZE && dict[1] < start + ALPHA_SIZE - 1){
            ++dict[1];
        }
// if the first letter of dict <= z and the second letter of dict >= z
        else if(dict[0] < (start + ALPHA_SIZE - 1) && dict[1] >= start + ALPHA_SIZE - 1){
            ++dict[0];
            dict[1] = start;
        }
// the first letter of dict >= z
        else
            break;
        ele = new node<Word>(dict);
    }
}

Hash_indexer::~Hash_indexer()
{
// Delete dynamic memory from node objects
    for(node<Word>* ele : index){
        list_clear(ele);
    }
}

std::size_t Hash_indexer::get_size(std::string list_indx)
{
    return list_length(index[hash_word(list_indx)]) - 1;// subtract head node from size
}

node<Word>* Hash_indexer::find_word(std::string str)
{
    node<Word> *tmp_word = index[hash_word(str)];

// While there is a next element look for the Word that holds str
    while(tmp_word->link() != nullptr){
        if(tmp_word->link()->data().get_word() == str)
            return tmp_word->link();
        tmp_word = tmp_word->link();
    }
// If str isn't found, return a nullptr
    return nullptr;
}

void Hash_indexer::add(Word arg_word)
{
    node<Word> *tmp_word = index[hash_word(arg_word.get_word())]; // find general dicitionary position of word, using built in def of operator[]
    node<Word> *target = find_word(arg_word.get_word());

// If arg_word hasn't been added to index
    if(target == nullptr ){
        bool stop_check = true;

// Don't check if the dicitionary labels in the first position of each index element are stop words
        if(list_length(tmp_word) > 0){
            std::string stop_file = "../../stop_words.txt";
            stop_check = !(arg_word.is_stopword(stop_file, arg_word.get_word()));
        }
        if(stop_check){
            std::size_t pos = list_length(tmp_word); // get position of last element in list
            node<Word> *prev_word = list_locate(tmp_word, pos); // get pointer to last element
            list_insert(prev_word, arg_word); // insert element
        }
    }
    else{
// If arg_word is already in index, add is to that Word
        target->data() += arg_word;
    }
}

// AUXILARY MEMBER FUNCTIONS //

std::size_t Hash_indexer::hash_word(std::string word) const
{
// Use ASCII char dec values to find position of word with 2 or more char
    if(word.size() >= 2 && isalpha(word[0]) && isalpha(word[1])){
        unsigned first = (static_cast<unsigned>(word[0]) - 96);
        unsigned second = (static_cast<unsigned>(word[1]) - 96);
        unsigned idx = (first - 1) * ALPHA_SIZE + second - 1;
        return idx;
    }
// Use ASCII char dec values to find position of word with 1 char
    else if(word.size() == 1 && isalpha(word[0])){
        unsigned first = (static_cast<unsigned>(word[0]) - 96);
        unsigned idx = (first - 1) * ALPHA_SIZE;
        return idx;
    }
    return 0;
}

void Hash_indexer::gen_webpage()
{
    unsigned header_lv = 1;

//Loop through Hash_indexer
    for(auto ele : index){

//Only generate pages for elements with words
        if(ele->link() != nullptr){
            node<Word> *tmp_word = ele->link();

//Loop through linked list of words
            while(tmp_word->link() != nullptr){

//Create and initialize fstream with file to generate webpage in
            std::string path = "webpages_hash/" + tmp_word->data().get_word() + ".html";
            std::fstream txt("webpages_hash/" + tmp_word->data().get_word() + ".html", std::fstream::in | std::fstream::out| std::fstream::trunc);

//Call class to generate webpage
            Cpp_webpage page("Index for : " + tmp_word->data().get_word(), "Index for : " + tmp_word->data().get_word(), header_lv, txt, tmp_word->data().to_string());

//Move to next word
            tmp_word = tmp_word->link();
            txt.close();
            }
        }
    }
}
// FRIENDS //
std::ostream& operator<<(std::ostream &out, const Hash_indexer &obj)
{
// Iterate through each head node element of index
    for(auto ele : obj.index){
        node<Word> *tmp_node = ele;

// If the node has Word objects stored in it, write each one to STDOUT
        while(tmp_node->link() != nullptr){
            out << tmp_node->link()->data() << std::endl;
            tmp_node = tmp_node->link();
        }
    }
    return out;
}
