//DATE: 11/28/14
//ASSIGNMENT: Project 7
//FILE: customer.h
//DESC: Definition and implementation of Customer class. This type allows effcient storage of customer information

#ifndef CUSTOMER_H
#define CUSTORMER_H

#include <string>
#include <iostream>

class Customer{
public:

// CONSTRUCTORS //
    Customer(std::string arg_name = "N/A", std::string arg_address = "N/A", long  arg_phone = 0) : name(arg_name), address(arg_address), phone(arg_phone) { }

// MEMBER FUNCTIONS//
    void set_name(std::string arg_name) { name = arg_name;}
    std::string get_name() { return name; }
    void set_address(std::string arg_address) { address = arg_address; }
    std::string get_address() { return address; }
    void set_phone(long arg_phone) { phone = arg_phone; }
    int get_phone() { return phone; }

private:
// DATA MEMEBERS //
    std::string name;
    std::string address;

public:
    long phone;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const Customer obj);
};

    std::ostream& operator<<(std::ostream &out, const Customer obj)
    {
        out << obj.name << ' ' << obj.address << ' ' << obj.phone;
        return out;
    }
#endif
