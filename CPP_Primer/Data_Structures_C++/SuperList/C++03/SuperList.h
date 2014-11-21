//Project 3
//10/01/14
//SuperList.h
//Class definition for linked list container that uses the node class

#ifndef SUPERLIST_H
#define SUPERLIST_H

#include <iostream>
#include <string>
#include "node1.h"

class SuperList{
    public:

//CONSTRUCTORS//
    SuperList();

//MEMBER FUNCTIONS//
    bool isEmpty() const;
    bool isFull() const;
    void insertFront(std::string newItem);
    void insertRear(std::string newitem);
    bool removeOne(std::string item);
    std::string removeFirst();
    void removeN(int N, std::string result[]);
    std::string reportFirst() const;
    int reportWhere(std::string item) const;
    int lengthIs() const;
    bool operator==(const SuperList &rhs) const;

//FRIENDS//
    friend std::ostream& operator<<(std::ostream &out, const SuperList &obj);

    private:

    node *head_ptr;
};

#endif
