// DATE : 08/10/15
// FILE : 08.10.15.cpp
// DESC : C++ primer exercises : 2.41, 2.42, 3.1, 3.2

#include <iostream>
#include <string>
#include "Sales_data.h"

using std::cout;
using std::cerr;
using std::endl;
using std::cin;

struct Sales_data;

int main()
{
/*
// Ex 2.41
    Sales_data book;
    double price(0.0);
    std::cin >> book.bookNo >> book.units_sold >> price;
    book.revenue = book.units_sold * price;

    std::cout << book.bookNo << " " << book.units_sold << " " << book.revenue << std::endl;

// Ex 2.42
    Sales_data data1, data2;
    std::cin >> data1.bookNo >> data1.units_sold >> data1.revenue
        >> data2.bookNo >> data2.units_sold >> data2.revenue;

    if(data1.bookNo == data2.bookNo){
        Sales_data total;
        total.bookNo = data1.bookNo;
        total.units_sold = data1.units_sold + data2.units_sold;
        total.revenue = data1.revenue + data2.revenue;
        std::cout << "total : " << total.bookNo << " " << total.units_sold << " " << total.revenue << std::endl;
    }

// Ex 3.1
    int sum = 0, val = 1;
    while(val <= 10){
        sum += val;
        ++val;
    }
    cout << "Sum of 1 to 10 inclusive is " << sum << endl;

    Sales_data data1, data2;
    double price(0.0);

    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = price * data1.units_sold;

    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = price * data2.units_sold;

    if(data1.bookNo == data2.bookNo){
        unsigned totalCnt = data1.units_sold + data2.units_sold;
        double totalRevenue = data1.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if(totalCnt != 0)
            cout << totalRevenue / totalCnt << endl;
        else
            cout << "(no sales)" << endl;
        return 0;
    }
    else{
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }

// Ex 3.2
    std::string str;
    while(std::getline(std::cin, str) && !str.empty())
        ;
    std::cout << "Loop #1 complete" << std::endl;

    while(std::cin >> str)
        ;

    std::cout << "Loop #2 complete" << std::endl;
*/
    return 0;
}

#ifndef SALES_DATA_H
#define SALES_DATA_H
struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};
#endif
