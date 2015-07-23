// DATE : 07/22/15
// FILE : APAN:07.23.15.cpp
// DESC : Define a reference-counted class, which manually counts the number of objects of class type sharing resources

#include <iostream>
#include <string>

// Reference-counted class
class Ref{

public :

// COPY CONTROL //
    Ref(char ch = 0) : pch(new char(ch)), cnt(new std::size_t(1)) { }// Default constructos
    Ref(const Ref &obj) : dval(obj.dval), pch(obj.pch), cnt(obj.cnt) { ++*cnt; }// Copy constructor
    Ref& operator=(const Ref &rhs)// Copy-assignment operator
    {
        if(this == &rhs)
            return *this;
        else{

// Update counters
        ++*rhs.cnt;
        if(!(--cnt)){
            delete pch;
            delete cnt;
        }

// Work of constructor
        dval = rhs.dval;
        pch = rhs.pch;
        cnt = rhs.cnt;
        }
        return *this;
    }

    ~Ref()// Destructor
    {
        if(!(--cnt)){
            delete pch;
            delete cnt;
        }
    }

// MEMBER FUNCTIONS //
    std::size_t* get_cnt() { return cnt; }

private :

// DATA MEMBERS //
    double dval = 743.43;
    char *pch;
    std::size_t *cnt;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const Ref &obj);
};

std::ostream& operator<<(std::ostream &out, const Ref &obj)
{
    out << "dval : " << obj.dval << '\n'
        << "pch : " << *obj.pch << '\n'
        << "cnt : " << *obj.cnt << '\n';

    return out;
}

int main()
{
// Create reference objects and display count after creation, copy, assignment
    Ref r0;
    std::cout << r0 << std::endl;

    Ref r1(r0);
    std::cout << r1 << std::endl;

    Ref r2 = r1;
    std::cout << r2 << std::endl;

    Ref r3;
    std::cout << r3 << std::endl;

    r3 = r0;
    std::cout << r3 << std::endl;

    return 0;
}
