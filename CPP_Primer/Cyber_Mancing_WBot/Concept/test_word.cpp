// Test Word class

#include <iostream>
#include <string>
#include "Word.h"
#include <set>

int main()
{
//Test all constructors
    Word w0;
    Word w1("Net");
    Word w2("Las", 2, "http://www.macys.com http://www.nordstroms.com");

    std::cout << w0 << std::endl;
    std::cout << w1 << std::endl;
    std::cout << w2 << std::endl;

//Test all setter and getter methods
    w0.set_word("Enc");
    std::cout << "w0 word : " << w0.get_word() << std::endl;
    w0.set_count(1);
    std::cout << "w0 count : " << w0.get_count() << std::endl;
    w0.add_url("http://www.kungfu.com");
    std::cout << "w0 URLs : " << w0.get_url() << std::endl;

    w1.set_word("Net++");
    std::cout << "w1 word : " << w1.get_word() << std::endl;
    w1.set_count(0);
    std::cout << "w1 count : " << w1.get_count() << std::endl;
    w1.add_url("http://www.bubble.com");
    std::cout << "w1 URLs : " << w1.get_url() << std::endl;

    w2.set_word("Las++");
    std::cout << "w2 word : " << w2.get_word() << std::endl;
    w2.set_count(3);
    std::cout << "w2 count : " << w2.get_count() << std::endl;
    w2.add_url("http://www.guess.com");
    std::cout << "w2 URLs : " << w2.get_url() << std::endl;

    //Test empty()
    std::cout << std::boolalpha;
    std::cout << w0.empty() << std::endl;
    std::cout << w1.empty() << std::endl;
    std::cout << w2.empty() << std::endl;

    return 0;
}
