//Project 7 : Part A
//FILE : Book.h
//DESC : Defines the derived class of LendItems,the Book class

#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include "LendItem.h"

class Book : public LendItem{

//Data members//
    std::string author;

//'S' or 'H'
    char coverType;

    public:

//Constructors//
    Book();
    Book(std::string title, std::string auth, char cover);

//Member Functions//
    void setAuthor(std::string auth);
    void setCover(char type);
    std::string getAuth();
    char getCover();
    void printAll(std::ostream &out, LendItem ** arr);
};

#endif
