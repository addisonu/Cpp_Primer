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

//Test lower_word
    Word w2("Las", 2, "http://www.macys.com http://www.nordstroms.com");

    std::cout << w0 << std::endl;
    std::cout << w1 << std::endl;
    std::cout << w2 << std::endl;

//Test all setter and getter methods
    w0.set_word("Enc");
    std::cout << "w0 word : " << w0.get_word() << std::endl;
    w0.set_count(0);
    std::cout << "w0 count : " << w0.get_count() << std::endl;
    w0.add_url("http://www.kungfu.com");
    w0.add_url("http://www.kungfu1.com");//adding duplicate url
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

    w2 = w1;
    std::cout << "w0 : \n";
    std::cout << w0 << std::endl;
    std::cout << "w1 : \n";
    std::cout << w1.to_string() << std::endl;
    std::cout << "w2 : \n";
    std::cout << w2 << std::endl;

    //Test operator+=
    Word w3("Enc", 0, "");
    w3.add_url("http://www.kungfu2.com");
    w3.add_url("http://www.kungfu3.com");//adding duplicate url
    std::cout << "w3 : " << w3 << std::endl;
    w0 += w2;
    w0 += w3;
    std::cout << "w0 + w3 " << w0 << std::endl;

    //Test is_stopword
    std::string stop_file = "../../stop_words.txt";
    std::string words[]{"weq", "a", "you", "it", "food", "and", "green", "then"};
    for(const auto str : words){
        std::cout << str << " is stop word : " << w3.is_stopword(stop_file, str) << std::endl;
    }
    return 0;
}
