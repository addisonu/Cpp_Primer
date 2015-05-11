// DATE : 05/10/15
// FILE : APAN:05.10.15.cpp
// DESC : Create function template to generate function with parameters of built-in and class types

#include <iostream>
#include <vector>

using std::vector<int>;
// Create class type to be passed to function, must overload operator<
class Demo{
public :

// CONSTRUCTORS //
    Demo() { }
    Demo(int val1, std::string val2, std::vector<double> val3)
    {
        ival = val1;
        sval = val2;
        vval = val3;
    }

// MEMBER FUNCTIONS //
    void set_ival(int val) { ival = val; }
    int get_ival() { return ival; }

    void set_sval(std::string val) { sval = val; }
    std::string& get_sval() { return sval; }

    void set_vval(std::vector<double> val) { vval = val; }
    std::vector<double> get_vval() { return vval; }

    bool operator<(const Demo rhs) const
    {
        return (ival < rhs.ival) && (sval < rhs.sval) && (vval < rhs.vval);
    }

private :

// DATA MEMBERS //
    int ival  = 0;
    std::vector<double> vval = {1.1, 2.2, 3.3};
    std::string sval = "string data member";
};

// Forward declarations
template <typename T> T min(const T lhs, const T rhs);

int main()
{
// Call min on built-in types
    std::cout << min(2,3) << std::endl;
    std::cout << min(3.14, 2.41) << std::endl;

// Call min on libray types
    std::string str1("Zally"), str2("Maddy");
    //std::cout << min(str1, str2) << std::endl;
    std::vector<int> uvec0, uvec1(2, 2), uvec2(3, 5);
    uvec0 = min(uvec1, uvec2);// << std::endl;

// Call min on Demo where d1 < d2
    Demo d0, d1(1, "one", {4.4, 5.5}), d2(23, "twenty-three", {23.23});
    d0 = min(d1, d2);
    std::cout << "ival = " << d0.get_ival() << std::endl << "sval = " << d0.get_sval() << std::endl
        << "vval : ";
    for(auto val : d0.get_vval())
        std::cout << std::endl << '\t' << val;
    std::cout << std::endl;

     return 0;
}

template <typename T> T min(const T lhs, const T rhs)
{
    if(lhs < rhs)
        return lhs;
    else
        return rhs;
}
