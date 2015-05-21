// DATE : 05/19/15
// FILE : APAN:05.19.15.cpp
// DESC : Variable length parameter list

#include <iostream>
#include <string>

// Forward declarations
template <typename T, typename... args> double avg(const T &num, const args&... nums);
template <typename T, typename... args> double sum(const T &num, const args&... nums);
template <typename T> double sum(const T &num);
template <class T, class...args> std::ostream& print(std::ostream &out, const T &obj, const args&... objs);
template <class T> std::ostream& print(std::ostream &out, const T &obj);

int main(){

// Invoke avg
    std::cout << avg(1, 2, 3, 4, 5, 6, 7) << std::endl;

// Invoke print
    print(std::cout, "first", 2, 3.14, 'c', -8, "last");
    return 0;
}

template <typename T, typename... args> double avg(const T &num, const args&... nums){
    return sum(num, nums...) / (sizeof...(args) + 1);
}
template <typename T, typename... args> double sum(const T &num, const args&... nums)
{
    return num + sum(nums...);
}

template <typename T> double sum(const T &num)
{
    return num;
}

template <class T, class...args> std::ostream& print(std::ostream &out, const T &obj, const args&... objs)
{
    out << obj << ", size : " << sizeof(obj) << std::endl;
    return print(out, objs...);
}

template <class T> std::ostream& print(std::ostream &out, const T &obj)
{
    return out << obj << ", size : " << sizeof(obj) << std::endl;
}
