// DATE : 05/12/15
// FILE : APAN:05.12.15.cpp
// DESC : Class that has dynamic memory and defines copy control members
//  1) Constructor
//  2) Destructor
//  3) Copy Assignment

#include <iostream>

// Class definition

class CC{
public :

// CONSTRUCTORS //
    CC() : cpt(new char[cap]) { }

// COPY CONTROL //
    CC(const CC &rhs)
    {
        *this = rhs;
    }

    CC& operator=(const CC &rhs)
    {
// check if argument is the same as this
    if(this == &rhs)
        return *this;
    else {

// deallocate old memory
        if(cpt)
            delete[] cpt;

// memberwise copy nonreference and pointer members
        cap = rhs.cap;
        size = rhs.size;

// create new pointer with copy of elements
        if(rhs.cpt){
            char *trans = new char[rhs.cap];
            for(std::size_t i = 0; i != size + 1; ++i){
                trans[i] = rhs.cpt[i];
            }
            cpt = trans;
            trans = nullptr;
        }
        else
            cpt = nullptr;
    }
    return *this;
    }

    ~ CC() { delete[] cpt; }

// MEMBER FUNCTIONS //
    unsigned get_size() { return size; }

    unsigned get_cap() { return cap; }

    void add_char(char val)
    {
        if((size) < cap){
            cpt[size] = val;
            cpt[++size] = '\0';
        }
        else{
            cap *= 2;
            CC tmp(*this);
            *this = tmp;
            cpt[size] = val;
            cpt[++size] = '\0';
        }
    }
private :

// DATA MEMBERS //
    char *cpt = nullptr;
    unsigned size = 0;
    unsigned cap = 10;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const CC &rhs);
};

std::ostream& operator<<(std::ostream &out, const CC &rhs)
{
    std::cout << "size : " << rhs.size << std::endl
        << "capacity : " << rhs.cap << std::endl;

    for(std::size_t i = 0; i != rhs.size; i++)
        std::cout << rhs.cpt[i];

    return out;
}

int main()
{
    CC c0;
    CC c1;

// Add char to the c0
    for(std::size_t i = 0; i != 26; ++i)
        c0.add_char('a' + i);

    std::cout << "c0 : " << c0 << std::endl;
    std::cout << "c1 : " << c1 << std::endl;

    return 0;
}
