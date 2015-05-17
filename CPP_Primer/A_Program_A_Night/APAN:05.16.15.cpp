// DATE : 05/16/15
// FILE : APAN:05.16.15.cpp
// DESC : Flow-of-control
//  1) Conditional : if, if-else-if, if-else, switch
//  2) Iterative : while, for, range for, do-while
//  3) Jump : break, continue, goto, return
//  4) Try

#include <iostream>
#include <vector>
#include <string>
#include <exception>

int main()
{
// var to use in following statements
    int val0(0), val1(1), val2(2);
    bool status(false);
    constexpr unsigned char a('a'), u('u'), z('z');
    char ch(1);;
    std::string str;

// if-else if-else
    std::cout << "Enter a char : \n";
    std::cin.get(ch);

    std::cout << "\nif-else : " << std::endl;
    if(ch == a)
        std::cout << a << std::endl;
    else if(ch == u)
        std::cout << u << std::endl;
    else if(ch == z){
        if(a + u)
            std::cout << a << u;
        std::cout << z << std::endl;
    }
    else
        std::cout << ch << std::endl;

// switch
    std::cout << "\nswitch : " << std::endl;
    switch(ch){
        case a:
        {
            std::cout << a << std::endl;
            break;
        }
        case u:
        {
            std::cout << u << std::endl;
            break;
        }
        case z:
        {
            std::cout << z << std::endl;
            break;
        }
        default:
        {
            std::cout << ch << std::endl;
            break;
        }
    }

// while loop
    str = "This is a loop u || z test string";
    std::string::iterator it = str.begin();

    std::cout << "\nwhile : " << std::endl;
    while(++it, (it != str.end() && *it != ch ))
        ; // null statement, just find substring starting at ch

    if(it != str.end())
        std::cout << std::string(it, str.end()) << std::endl;
    else
        std::cout << "char not found" << std::endl;

// for
    std::cout << "\nfor : " << std::endl;
    for(auto it = str.begin(); it != str.end(); ++it)
        std::cout << *it;
    std::cout << std::endl;

// range for
    std::cout << "\nrange for : " << std::endl;
    for(decltype(ch) val : str)
        std::cout << val;
    std::cout << std::endl;

// do-while
    std::cout << "\ndo-while : " << std::endl;
    if(it != str.end())
        do{
            if(*it == ch)
                continue;
            std::cout << *it;
        }while(it++ != str.end());
    else
        std::cout << "char not found";

    std::cout << '\n' << std::endl;

// try
    try{
        switch(ch){
            case a:
            {
                throw std::runtime_error("catch a");
                break;
            }
            case u:
            {
                throw std::range_error("catch u");
                break;
            }
            case z:
            {
                throw std::overflow_error("catch z");
                break;
            }
            default:
            {
                throw std::logic_error("catch default");
                break;
            }
        }
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    catch(std::range_error &e){
        std::cout << e.what() << std::endl;
    }
    catch(std::overflow_error &e){
        std::cout << e.what() << std::endl;
    }
    catch(...){
        std::cout << "Default catch." << std::endl;
        goto end;
    }
    std::cout << std::endl;
        end:
            return 1;

    return 0;
}

