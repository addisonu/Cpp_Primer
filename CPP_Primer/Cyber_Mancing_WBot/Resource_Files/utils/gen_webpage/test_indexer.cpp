// Test Indexer class

#include <iostream>
#include <string>
#include <vector>
#include "Indexer.h"

int main()
{
//Test constructors
    Indexer idx0, idx1;

//Test setters/getters
    Word w0, w1("w1", 1, "http://www.w1.com");
    std::cout << "w0\n" << w0 << std::endl;
    std::cout << "w1\n" << w1 << std::endl << std::endl;
    idx0.add(w0);
    w1.add_url("http://www.yummy.com");
    idx1.add(w1);
    std::cout << "find_word() => " << idx1.find_word(w1.get_word(), w0) << " end" << std::endl;

//Test find_word
    std::cout << "idx0[w0.word]\n" << idx0[w0.get_word()] << std::endl;
    std::cout << "idx1[w1.word]\n" << idx1[w1.get_word()] << std::endl;

//Test function to generate webpage
    idx0.gen_indxpg();
    idx1.gen_indxpg();
    return 0;
}
