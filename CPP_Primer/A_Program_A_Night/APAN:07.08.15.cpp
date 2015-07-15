// DATE : 07/08/15
// FILE : APAN:07.08.15.cpp
// DESC : Tuple

#include <iostream>
#include <tuple>
#include <string>
#include <vector>

// Class to use ase type for tuple element
class A{
public:
    A() { }
    A(char a_arg, char b_arg) : a(a_arg), b(b_arg) { }

private:
    char a = 'a';
    char b = 'b';

    friend std::ostream& operator<<(std::ostream& out, const A &obj);
};

std::ostream& operator<<(std::ostream &out, const A &obj)
{
    out << "a : " << obj.a << std::endl;
    out << "b : " << obj.b << std::endl;
    return out;
}

int main()
{
// Aliases
    using tp0 = std::string;
    using tp1 = std::vector<std::string>;
    using tp2 = char;
    typedef double tp3;
    typedef std::vector<double> tp4;
    typedef const char (*tp5)[6];

// Elements of tuples
    tp0 str0("string0");
    tp1 svec0 = {"string1", "string2", "string3"};
    tp2 ch0('u');
    tp3 d0(5.44);
    tp4 dvec(5, 4.53);
    const char cstr[] = "Hello";
    tp5 pt_cstr0 = & cstr;
    A objA(8, 7);

// Define tuple objects
    std::tuple<tp0, tp1, tp2> tpl0;
    std::tuple<tp0, tp1, tp2> tpl1(str0, svec0, ch0);
    std::tuple<tp3, tp4, tp5> tpl2 = std::make_tuple(d0, dvec, pt_cstr0);
    std::tuple<tp0, tp1, tp2, tp3, tp4, tp5, A> tpl3(str0, svec0, ch0, d0, dvec, pt_cstr0, objA);

// Use tuple operations
    std::cout << std::boolalpha;
    std::cout << "tpl0 == tpl1 : " << (tpl0 == tpl1) << std::endl;
    std::cout << "tpl0 != tpl1 : " << (tpl0 != tpl1) << std::endl;
    std::cout << "tpl0 <= tpl1 : " << (tpl0 <= tpl1) << std::endl;
    std::cout << "tpl0 >= tpl1 : " << (tpl0 >= tpl1) << std::endl;

// Print the first element of each tuple
    std::cout << "tpl0<0> : " << std::get<0>(tpl0) << std::endl;
    std::cout << "tpl1<0> : " << std::get<0>(tpl1) << std::endl;
    std::cout << "tpl2<0> : " << std::get<0>(tpl2) << std::endl;
    std::cout << "tpl3<0> : " << std::get<0>(tpl3) << std::endl;

// Print the size of each tuple
    std::cout << "tpl0 size " << std::tuple_size<decltype(tpl0)>::value << std::endl;
    std::cout << "tpl1 size " << std::tuple_size<decltype(tpl1)>::value << std::endl;
    std::cout << "tpl2 size " << std::tuple_size<decltype(tpl2)>::value << std::endl;
    std::cout << "tpl3 size " << std::tuple_size<decltype(tpl3)>::value << std::endl;

    return 0;
}
