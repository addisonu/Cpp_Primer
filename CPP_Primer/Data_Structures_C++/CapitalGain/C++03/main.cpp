//10/16/14
//Project 4
//main.cpp
//Unit tests for Transaction and QueueT class

#include <iostream>
#include <list>
#include <string>
#include <stdexcept>
#include "Transaction.h"
#include "QueueT.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;


std::ostream& div(std::ostream &out, const string &label);

int main()
{
    div(cout, "=");
//Tests for QueueT class//
    div(cout, "Queue Test");

//Default constructor
    div(cout, "Queue(): PASS");
    Queue<Transaction> q1(2);
    cout << "q1:\n" << q1;
    div(cout, "=");
//Constructor initializes list argument with capacity cap
    div(cout, "Queue(cap) : PASS");
    Queue<Transaction> q2;
    cout << "q2:\n" << q2;
    div(cout, "=");
//adds item to the end of the queue
    div(cout, "add(item) : PASS");
    Transaction t1(7.77, 8, 999);
    q1.add(t1);
    cout << "q1:\n" << q1;
    div(cout, "=");
//returns true if the queue is empty
    div(cout, "isEmpty() : PASS");
    cout << "q1 is empty : " << q1.isEmpty() << endl;
    Queue<Transaction> q3(0);
    cout << "q3 is empty : " << q3.isEmpty() << endl;
    div(cout, "=");
//removes the front item from the queue
    div(cout, "remove() : PASS");
    q3.add(t1);
    cout << "q3:\n" << q3;
    q3.remove();
    cout << "q3:\n" << q3;
    div(cout, "=");
//to provide a copy of the object that is first in the queue (the next one to be removed)
    div(cout, "first() : PASS");
    Transaction t3(76.9, 2, 3879);
    q3.add(t1);
    q3.add(t3);
    cout << "q3:\n" << q3;
    cout << "The first item in q3 is : " << q3.first() << endl;
    div(cout, "=");
//updates the item in the front of the queue
    div(cout, "updateFirst() : PASS");
    cout << "q1:\n" << q1;
    q1.updateFirst(t1);
    cout << "q1:\n" << q1;
    div(cout, "=");


//Tests for Transaction class//
    div(cout, "Transaction Tests");

//Constructor initializes data members of Transaction object
    div(cout, "Transaction(price, quan, idno) : PASS");
    Transaction t2(76.9, 2, 3879);
    cout << t2 << endl;
    div(cout, "=");
//Set the quantity data member
    div(cout, "setQuan(quan) : PASS");
    t2.setQuan(6);
    cout << t2 << endl;
    div(cout, "=");
//Return the price data member
    div(cout, "getPrice() : PASS");
    cout << "price = " << t2.getPrice() << endl;
    div(cout, "=");
//Return the quantity data member
    div(cout, "getQuan() : PASS");
    cout << "quantity = " << t2.getQuan() << endl;
    div(cout, "=");

    return 0;
}

std::ostream& div(std::ostream &out, const string &label)
{
    if(label == "="){
        cout << string(50, '=') << endl;
    }
    else{
        out << label << endl;
        cout << string(50, '=') << endl;
    }
    return out;
}
