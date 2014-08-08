//Project 7 : Part A
//FILE : LendItem.h
//DESC : Base class for LendItem class automated record keeping system

#ifndef LEND_ITEM_H
#define LEND_ITEM_H

#include <iostream>
#include <string>

class LendItem{

//Data members//

    protected:

    int borrowNumber;
//mediumType is ‘B’for book or ‘D’ for DVD
    char mediumType;
    bool borrowed;
    std::string title;

    public:

    static int LI_size;

//Constructors//
    LendItem();
    LendItem(std::string title, char med);

//Member Functions//
    void setTitle(std::string manu);
    void setMedium(char med);
    void setBNumber(int bNumber);
    void setBorrowed(bool bstatus);
    bool getBorrowed() const;
    std::string getTitle();
    char getMedium();
    int getBNumber();

//Virtual functions that may be defined in each derived class//
    virtual void printAll(std::ostream &out, LendItem ** arr) = 0;

//Friends//
    friend std::ostream& operator<<(std::ostream &out, const LendItem &obj);
};

#endif
