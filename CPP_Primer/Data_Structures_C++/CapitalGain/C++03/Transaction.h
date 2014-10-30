//10/16/14
//Project 4
//Transaction.h
//Class definition and implementation for creating and maintaining transactions for each stock purchase and sell

#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>
#include <string>

class Transaction {

public:

//CONSTRUCTORS//
    Transaction(double sprice = 0, int squantity = 0, int sidNo = 0) : price(sprice), quantity(squantity), vendorID(sidNo) {}

//GENERAL MEMBER FUNCTIONS//
    void setQuan(int squantity) {quantity = squantity;}
    double getPrice() {return price;}
    int getQuan() {return quantity;}

//FRIENDS//
    friend std::ostream& operator<<(std::ostream &out, const Transaction &obj);

private:

//DATA MEMBERS//
    double price;
    int quantity;
    int vendorID;
};

std::ostream& operator<<(std::ostream &out, const Transaction &obj)
{
    out << obj.price << " " << obj.quantity << " " << obj.vendorID;
    return out;
}

#endif
