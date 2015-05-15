// DATE : 05/14/15
// FILE : APAN:05.14.15.cpp
// DESC : Series of expressions that leverage operator precedence

#include <iostream>
#include <string>

// var with global scope
std::string global("global");

// class to declare pointer to member function
class A{
public :
    A() {  }
    A(int val) { a = val; }
    int get_a() { return a; }
private :
    int a;
};

int main()
{
// variables for following expressions
    int global(7); // local scope
    std::size_t idx(1);
    double val1(3.14), val2(2.41), val3(7.77);
    char carr[3]{7 + 'c', 8 + 'b', 9 + 'a'};
    char *ccp = carr;
    std::string sarr[2] = {"string1", "string22"};
    std::string *str0 = &::global, *str1 = sarr;
    A obj(7), *pobj = &obj;
    int (A::*pA)() = &A::get_a;

// Use combination of operators, trailing comment identifies order operators are evaluated

    float fval = val1 + ::global.size(); // global scope -> member access -> call -> addition -> assignment

    std::cout << "element in carr : " << (val1 == val2 ? ++ccp[idx--] : ++ccp[idx++]) << std::endl; // namespace scope -> conditional -> [post decrement -> subscript -> pre increment] or [post increment -> subscript -> pre increment] -> namespace scope -> left shift

    std::cout << "size of the second string : " << (++str1)->size() << std::endl; // namespace scope -> left shift -> pre increment -> member access -> call -> left shift -> namespace scope

    std::cout << "size of the second string : " << (*str0)[3] << std::endl; // namespace scope -> left shift -> dereference -> subscript -> left shift -> namespace scope

    std::cout << "obj.a : " << (pobj->*pA)() << std::endl; // namespace scope -> left shift -> pointer to member select -> call -> left shift -> namespace scope -> left shift

    return 0;
}
