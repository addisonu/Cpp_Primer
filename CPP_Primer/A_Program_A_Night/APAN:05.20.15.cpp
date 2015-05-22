// DATE : 05/20/15
// FILE : APAN:05.20.15.cpp
// DESC : Define instances for a template class using template specializations

#include <iostream>
#include <string>
#include <vector>

// Forward declarations
template <typename T> class Tclass;
template <typename T> std::ostream& operator<<(std::ostream &out, const Tclass<T> &obj);

template <typename T> class Tclass{

public :

// TYPE MEMBERS //
    using type = T;

// MEMBER FUNCTIONS //
    Tclass(type val) { a = val; }
    void set(type val) { a = val; }
    type get() { return a;}

private :

// DATA MEMBERS //
    type a;

// FRIENDS //
    friend std::ostream& operator<<<type>(std::ostream &out, const Tclass<type> &obj);
};

template <typename T> std::ostream& operator<<(std::ostream &out, const Tclass<T> &obj)
{
    out << obj.a;
    return out;
}


template <> std::ostream& operator<<(std::ostream &out, const Tclass<int> &obj)
{
    out << obj.a * obj.a;
    return out;
}

template <> void Tclass<int>::set(int val) { a = val * val; }

template <> int Tclass<int>::get() { return a * a; }

int main()
{
    Tclass<int> t0(7);
    std::cout << t0 << std::endl;
    t0.set(8);
    std::cout << t0.get() << std::endl;

    Tclass<std::string> t1("string arg");
    std::cout << t1 << std::endl;
    t1.set("another string arg");
    std::cout << t1.get() << std::endl;

    return 0;
}
