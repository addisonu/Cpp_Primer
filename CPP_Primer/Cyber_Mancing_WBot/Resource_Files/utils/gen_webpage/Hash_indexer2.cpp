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
 * hash_word only works for strings beginning with two letters - status [fixed] - problem [needed conditional branch for words length 1 and length > 1]
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

    for(auto &ele : index){
        if(dict[0] < start + ALPHA_SIZE && dict[1] < start + ALPHA_SIZE - 1){
            ++dict[1];
        }
        else if(dict[0] < (start + ALPHA_SIZE - 1) && dict[1] >= start + ALPHA_SIZE - 1){
            ++dict[0];
            dict[1] = start;
        }
        else
            break;
        ele = new node<Word>(dict);
    }
}

Hash_indexer::~Hash_indexer()
{
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
    while(tmp_word->link() != nullptr){
        if(tmp_word->link()->data().get_word() == str)
            return tmp_word->link();
        tmp_word = tmp_word->link();
    }
    return nullptr;
}

void Hash_indexer::add(Word arg_word)
{
    node<Word> *tmp_word = index[hash_word(arg_word.get_word())]; // find general dicitionary position of word, using built in def of operator[]
    node<Word> *target = find_word(arg_word.get_word());

    if(target == nullptr){
        std::size_t pos = list_length(tmp_word); // get position of last element in list
        node<Word> *prev_word = list_locate(tmp_word, pos); // get pointer to last element
        list_insert(prev_word, arg_word); // insert element
    }
    else{
        target->data() += arg_word;
    }
}

// AUXILARY MEMBER FUNCTIONS //

// PRECONDITION : word[0] and word[1] are alpha
// POSTCONDITION : position of correct head node for word in index is returned
std::size_t Hash_indexer::hash_word(std::string word) const
{
    if(word.size() >= 2 && isalpha(word[0]) && isalpha(word[1])){
        unsigned first = (static_cast<unsigned>(word[0]) - 96);
        unsigned second = (static_cast<unsigned>(word[1]) - 96);
        unsigned idx = (first - 1) * ALPHA_SIZE + second - 1;
        return idx;
    }
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
            std::cout << "word = " << tmp_word->data().get_word() << std::endl;
            std::string path = "webpages/" + tmp_word->data().get_word() + ".html";
            std::fstream txt("webpages/" + tmp_word->data().get_word() + ".html", std::fstream::in | std::fstream::out| std::fstream::trunc);

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
    for(auto ele : obj.index){
        node<Word> *tmp_node = ele;
        while(tmp_node->link() != nullptr){
            out << tmp_node->link()->data() << std::endl;
            tmp_node = tmp_node->link();
        }
    }
    return out;
}
