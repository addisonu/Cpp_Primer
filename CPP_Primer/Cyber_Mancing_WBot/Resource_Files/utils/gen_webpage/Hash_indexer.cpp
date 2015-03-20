// DATE : 03/18/15
// FILE : Hash_indexer.cpp
// DESC : Implementation of Hash_indexer class

// LEFT OFF //
/*
 * deciding which functions should be removed, changed, added
 */

// BUGS //
/*
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 * Add comments to all files
 * add preconditions and postconditions to all member functions
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
/*
// MODIFICATION MEMBER FUNCTIONS //
//not useful function, remove
void Hash_indexer::set_word(Word arg_word)// see note in Hash_indexer.h
{

}

//not useful function, remove
Word Hash_indexer::get_word()
{

}
*/
std::size_t Hash_indexer::get_size(std::string list_indx)
{
    return list_length(index[hash_word(list_indx)]) - 1;// subtract head node from size
}
/*
//not useful function, remove
void Hash_indexer::set_size(std::size_t val)
{

}
*/
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

// CONSTANT MEMBER FUNCTIONS //
// AUXILARY MEMBER FUNCTIONS //
std::size_t Hash_indexer::hash_word(std::string word) const
{
    unsigned first = (static_cast<unsigned>(word[0]) - 96);
    unsigned second = (static_cast<unsigned>(word[1]) - 96);
    unsigned idx = (first - 1) * ALPHA_SIZE + second - 1;
    return idx;
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
