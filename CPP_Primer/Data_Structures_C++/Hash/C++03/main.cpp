//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: main.cpp
//DESC: Unit tests for heap and patient classes

#include <iostream>
#include <string>
#include "table2.h"

void div(std::string label = "=", char outcome = 'N');

int main()
{
    std::cout << std::boolalpha;
////////////////////
// Tests for Customer and table classes
////////////////////
// Customer constructors //
//Customer(arg_name = "N/A", arg_address = "N/A", arg_phone = 0)
    div("Customer(arg_name, arg_address, arg_phone)");
    Customer c1("Shaniqua Jones", "Silver Berry ln", 9098764332);
    Customer c2("Daquan Brown", "Orange Ave", 1234567890);
    Customer c3("Charlet Green", "Yuciapa St" , 4325433220);
    Customer c4("Dannie Swift", "Apple St" , 4325433221);
    std::cout << "c1 : " << c1 << std::endl;
    std::cout << "c2 : " << c2 << std::endl;
    std::cout << "c3 : " << c3 << std::endl;
    std::cout << "c4 : " << c4 << std::endl;

// table( ) //
    div("table()", 'P');
    table<Customer> tb1;
    std::cout << "tb1 : \n" << tb1 << std::endl;

// table(const table& source) //
    div("table(source)", 'P');
    table<Customer> tb2(tb1);
    std::cout << "tb2 : \n" << tb2 << std::endl;

// void insert(const RecordType& entry) //
    div("insert(entry)", 'P');
    tb1.insert(c1);
    tb1.insert(c2);
    tb1.insert(c3);
    tb1.insert(c4);
    std::cout << "tb1 : \n" << tb1 << std::endl;
    std::cout << "tb1 : \n" << tb1 << std::endl;
    table<Customer> tb3(tb1);
    std::cout << "tb3 : \n" << tb3 << std::endl;

// void remove(int key) //
    div("remove(key)");
    std::cout << "tb1 : \n" << tb1 << std::endl;
    tb1.remove(c1.phone);
    std::cout << "tb1 : \n" << tb1 << std::endl;
    tb1.remove(c2.phone);
    std::cout << "tb1 : \n" << tb1 << std::endl;
    tb1.remove(c3.phone);

// void operator =(const table& source) //
    div("operator=(source)");
    std::cout << "tb1 : \n" << tb1 << std::endl;
    table<Customer> tb4 = tb1, tb5;
    tb5 = tb1;
    std::cout << "tb4 : \n" << tb4 << std::endl;
    std::cout << "tb5 : \n" << tb5 << std::endl;

// void find(int key, bool& found, RecordType& result) const //
    div("find(key, found, result)", 'P');
    tb2.insert(c2);
    bool found(0);
    Customer c4;
    tb1.find(c2.phone, found, c4);
    std::cout << "tb1 contains Shaniqua : " << found << std::endl;

// bool is_present(int key) const //
    div("is_present(key)", 'P');
    std::cout << "c1 is present : " << tb1.is_present(c1.phone) << std::endl;
    std::cout << "c2 is present : " << tb1.is_present(c2.phone) << std::endl;
    std::cout << "c3 is present : " << tb1.is_present(c3.phone) << std::endl;

// std::size_t size( ) //
    div("size()");
    std::cout << "size of tb2 : " << tb2.size() << std::endl;

    return 0;
}

void div(std::string label, char outcome)
{
    if(label == "=")
        std::cout << std::string(30, '=') << std::endl;
    else
        std::cout << std::string(30, '=') << std::endl << label << " : " << outcome << std::endl << std::string(30, '=') << std::endl;
}
