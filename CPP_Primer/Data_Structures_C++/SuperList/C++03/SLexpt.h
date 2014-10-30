 //Project 3
 //10/01/14
 //SLexpt.h
 //Exception class for SuperList

#ifndef LISTEXCEPTION_H
#define LISTEXCEPTION_H

#include <exception>

class ListException : public std::exception{
    public:

    virtual const char* what() const throw()
    {
        return "There is no more memory on the stack to add nodes to the list";
    }
};

#endif
