// DATE : 05/20/15
// FILE : APAN:05.20.15.cpp
// DESC : Define instances for a template class using template specializations

#include <iostream>
#include <string>
#include <vector>

// Forward declarations
template <typename T> class Tclass;
template <typename T> std::ostream& operator<<(std::ostream &out, const Tclass<T> &obj);
template <typename T> std::ostream& operator<<(std::ostream &out, const int &obj);


template <typename T> class Tclass{
// TYPE MEMBERS //

// MEMBER FUNCTIONS //
    Tclass(T val) { a = val; }

// DATA MEMBERS //
    private double a = 1.23;

// FRIENDS //
    friend std::ostream& operator<<<T>(std::ostream &out, const Tclass<T> &obj);
};

template <> std::ostream& operator<<(std::ostream &out, const int &obj)
{
    out << obj.a * obj.a;
}

int main()
{
    Tclass t(7);
    std::cout << t << std::endl;
    return 0;
}
