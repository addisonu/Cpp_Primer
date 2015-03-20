// DATE : 03/18/15
// FILE : test_hash_indexer.cpp
// DESC : Test Hash_indexer data structure

#include <iostream>
#include <string>
#include "node2.h"
#include "Hash_indexer.h"
#include "Word.h"

int main()
{
//Test constructor PASS
    Hash_indexer hi0;
    Word w0("aab", 1, "http://www.aa.com");
    hi0.add(w0);

//Test find_word PASS
    std::cout << hi0.find_word("aab")->data() << std::endl;

//Test get_size PASS
    std::cout << "size : " << hi0.get_size("aaTest") << std::endl;

//Test add and operator<< PASS
    Word w1("aaTest", 2, "http://www.ees.edu http://www.weis.dsa"); //new word
    hi0.add(w1);
    Word w2("aab", 1, "http://www.aa.com");// duplicate word
    hi0.add(w2);
    std::cout << hi0 << std::endl;
    return 0;
}
