// DATE : 05/30/15
// FILE : APAN:05.30.15.cpp
// DESC : Overload operator for class
//  1) operator<<
//  2) operator+
//  3) operator-
//  4) operator=
//  5) operator==
//  6) operator<
//  7) operator<=
//  8) operator>
//  9) operator>=


#include <iostream>
#include <string>

// Class definition
class Op{

public :

// TYPE MEMBERS //
    using type = std::string;

// MEMBER FUNCTIONS //
// CONSTRUCTORS //
    Op() { }
    Op(type str_arg, int val_arg) : str(str_arg), val(val_arg) { }
    Op(char ch, unsigned sz, int val_arg) : str(std::string(sz, ch)), val(val_arg) { }

// OTHER MEMBER FUNCTIONS //
    type get_str() { return str; }
    void set_str(type str_arg) { str = str_arg; }
    int get_val() { return val; }
    void set_val(int val_arg) { val = val_arg; }

// OVERELOADED OPERATORS //
    Op operator+(const Op &rhs)
    {
        Op tmp;
        tmp.str = str + rhs.str;
        tmp.val = val + rhs.val;
        return tmp;
    }

    Op operator+=(const Op &rhs)
    {
        this->str += rhs.str;
        return *this;
    }

    Op operator-(const Op &rhs)
    {
        Op tmp;
        tmp.val = val - rhs.val;
        return tmp;
    }

    Op operator-=(const Op &rhs)
    {
        this->val -= rhs.val;
        return *this;
    }

    Op operator=(const Op &rhs)
    {
        str = rhs.str;
        val = rhs.val;
        return *this;
    }

    bool operator==(const Op &rhs) { return str == rhs.str && val == rhs.val; }
    bool operator<(const Op &rhs) { return str < rhs.str && val < rhs.val; }
    bool operator<=(const Op &rhs) { return str <= rhs.str && val <= rhs.val; }
    bool operator>(const Op &rhs) { return str > rhs.str && val > rhs.val; }
    bool operator>=(const Op &rhs) { return str >= rhs.str && val >= rhs.val; }

// FRIENDS //
    friend std::ostream& operator<<(std::ostream& out, const Op &obj);

private :

// DATA MEMBERS //
    type str = "in class initializer";
    int val = 5;
};

std::ostream& operator<<(std::ostream& out, const Op &obj)
{
    out << "str : " << obj.str << std::endl << "val : " << obj.val;
    return out;
}

int main()
{
    Op obj0;
    Op obj1("string1", 1);
    Op obj2('u', 7, 7);
    std::cout << std::boolalpha;
    std::cout << "obj0 - \n" << obj0 << std::endl;
    std::cout << "obj1 - \n" << obj1 << std::endl;
    std::cout << "obj2 - \n" << obj2 << std::endl;
    std::cout << "(obj1 + obj2) - \n " << (obj1 + obj2) << std::endl;
    std::cout << "(obj0 - obj1) - \n " << (obj0 - obj1) << std::endl;
    std::cout << "(obj0 = obj1 + obj2) - \n " << (obj0 = obj1 + obj2) << std::endl;
    std::cout << "(obj1 == obj2) - \n " << (obj1 == obj2) << std::endl;
    std::cout << "(obj2 < obj0) - \n " << (obj2 < obj0) << std::endl;
    std::cout << "(obj1 <= obj2) - \n " << (obj1 <= obj2) << std::endl;
    std::cout << "(obj1 > obj1) - \n " << (obj1 > obj1) << std::endl;
    std::cout << "(obj2 >= obj2) - \n " << (obj2 >= obj2) << std::endl;

    return 0;
}
