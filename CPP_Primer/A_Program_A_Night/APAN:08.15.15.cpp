// DATE : 08/15/15
// FILE : APAN:08.15.15.cpp
// DESC : Make a class so that copy constructor and copy assignment operator can't be used

#include <iostream>
#include <string>

class UnCopyable {

protected:
    UnCopyable() { }
    ~UnCopyable() { }

private:
    UnCopyable(const UnCopyable&) { }
    UnCopyable& operator=(const UnCopyable&) { }
}

class A : private UnCopyable {

public:
    A();
    ~A();

private:
    int mem = 0;
};
