// DATE : 07/25/15
// FILE : APAN:07.25.15.cpp
// DESC : Give class move functionality by defining move constructor and move-assignment operator

#include <iostream>
#include <utility>
#include <string>

// Class with move operations
class Mov{

public :

// COPY CONTROL //
    Mov() : ival(new int(7)), str(new std::string("seven")) {  }

    Mov(int ival_arg, std::string str_arg) : ival(new int(ival_arg)), str(new std::string(str_arg)) {  }

    Mov(const Mov &) = default;

    ~Mov() = default;

    Mov(Mov &&rhs) noexcept : ival(rhs.ival), str(rhs.str){
        rhs.ival = nullptr;
        rhs.str = nullptr;
    }

    Mov& operator=(Mov &&rhs) noexcept
    {
        if(this != &rhs){
            ival = rhs.ival;
            str = rhs.str;

            rhs.ival = nullptr;
            rhs.str = nullptr;
        }
        return *this;
    }

private :

// DATA MEMBERS //
    int *ival;
    std::string *str;

// FRIENDS //
 friend std::ostream& operator<<(std::ostream& out, const Mov &obj);
};

std::ostream& operator<<(std::ostream &out, const Mov &obj)
{
    out << "ival : " << *obj.ival << '\n';
    out << "str : " << *obj.str << '\n';
    return out;
}

int main()
{
    Mov m0, m1(6, "six");
    std::cout << "m0 :\n" << m0 << std::endl;
    std::cout << "m1 :\n" << m1 << std::endl;

    m0 = std::move(m1);

    std::cout << "m0 :\n" << m0 << std::endl;

    return 0;
}
