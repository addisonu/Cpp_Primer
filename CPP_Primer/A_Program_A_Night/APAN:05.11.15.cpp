// DATE : 05/11/15
// FILE : APAN:05.11.15.cpp
// DESC : Write class template and create object
//  1) include member functions and friend function
//  2) overload operator== and operator<<

#include <iostream>
#include <vector>

// Forward declarations
    template <typename T1, typename T2> class Tmp;
    template <class T1, class T2> std::ostream& operator<<(std::ostream &out, const Tmp<T1, T2> &obj);

template <typename T1, typename T2> class Tmp{
public :

// CONSTRUCTORS //
    Tmp() { }

// MEMBER FUNCTIONS //
    int get_ival() const { return ival; }
    void set_ival(int val) { ival = val; }

    std::vector<T1> get_vec1() const { return vec1; }
    void set_vec1(std::vector<T1> val) { vec1 = val; }

    std::vector<T2> get_vec2() const { return vec2; }
    void set_vec2(std::vector<T2> val) { vec2 = val; }

    bool operator==(const Tmp &rhs) { return (ival == rhs.ival) && (vec1 == rhs.vec1) && (vec2 == rhs.vec2); }

private :

// DATA MEMBERS //
    int ival = 0;
    std::vector<T1> vec1;
    std::vector<T2> vec2;

// FRIENDS //
    friend std::ostream& operator<<<T1, T2>(std::ostream &out, const Tmp<T1, T2> &obj);
};

// Implement operator<<
template <class T1, class T2> std::ostream& operator<<(std::ostream &out, const Tmp<T1, T2> &obj)
{
    std::cout << obj.get_ival() << std::endl;

    for(auto val : obj.get_vec1())
        std::cout << val << " ";
    std::cout << std::endl;

    for(auto val : obj.get_vec2())
        std::cout << val << " ";

    return out;
}

// Demonstrate class in main
int main()
{
// Setup object of type Tmp t
    Tmp<int, std::string> t;
    std::string str1("str1");
    t.set_ival(7);
    t.set_vec1({3, 2, 1});
    t.set_vec2({"str0", "str1", "str2"});

// Setup object of type Tmp u
    Tmp<int, std::string> u;
    u.set_ival(7);
    u.set_vec1({2, 3, 1});
    u.set_vec2({"str0", "str1", "str2"});

// Setup object of type Tmp v
    Tmp<int, std::string> v;
    v.set_ival(7);
    v.set_vec1({3, 2, 1});
    v.set_vec2({"str0", "str1", "str2"});

// Compare t and u
    std::cout << std::boolalpha;
    std::cout << "t and u are equal : " << (t == u) << std::endl;

// Compare t and v
    std::cout << "t and v are equal : " << (t == v) << std::endl;

// Print t
    std::cout << t << std::endl;
    return 0;
}
