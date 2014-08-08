//Project 7 : Part A
//FILE : Book.cpp
//DESC : Implementation of derived class Book of abstract base class LendItem

#include <iostream>
#include <string>
#include "LendItem.h"
#include "Book.h"

Book::Book()
{
    mediumType ='B';
    author = "Null author";
    coverType = 'N';
}

Book::Book(std::string tle, std::string auth, char cover) : LendItem(tle, 'B'), author(auth), coverType(cover) { }

void Book::setAuthor(std::string auth)
{
    author = auth;
}

void Book::setCover(char type)
{
    coverType = type;
}

std::string Book::getAuth()
{
    return author;
}

char Book::getCover()
{
    return coverType;
}

void Book::printAll(std::ostream &out, LendItem ** arr)
{
    std::cout << " - Books currently owned by the Marina - " << std::endl;
    for(int n = 0; n < LI_size; n++){
        if(arr[n]->getMedium() == 'B'){
        std::cout << *arr[n] << std::endl;
        }
    }
}
