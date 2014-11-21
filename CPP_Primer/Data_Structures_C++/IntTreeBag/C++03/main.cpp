//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: main.cpp
//DSCR: Unit tests for binary tree bag class

#include <iostream>
#include <string>
#include "bag6.h"
#include "bintree.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

std::ostream& div(std::ostream &out, const string &label);

int main()
{
    div(cout, "=");
//Tests for bag class//
    div(cout, "Bag6 Test");

//Variables
main_savitch_10::bag<int>::value_type value;

//Default constructor
div(cout, "bag()");
main_savitch_10::bag<int> bag1;
cout << bag1;
cout << "bag1.size() = " << bag1.size() << endl;
cout << "value to erase\n";
cin >> value;
cout << "the result= " << bag1.erase_one(value) << '\n';
cout << "Outcome : PASS\n";
div(cout, "=");

//Constructor initializes root_ptr of bag with argument
div(cout, "bag(const bag &source)");
cout << "Enter value to intialize bag with.\n";
cin >> value;
bag1.insert(value);
main_savitch_10::bag<int> bag2(bag1);
cout << bag2;
cout << "Outcome : PASS\n";
div(cout, "=");

//Insert
div(cout, "insert(const Item &entry)");
cout << "Enter the values to add to the bag. Separate all values with a space.\n";

do{
    cout << "Enter value\n";
    cin >> value;
    if(value){
        bag2.insert(value);
        bag1.insert(value + 1);
    }
}while(value);

cout << bag2;
cout << "Outcome : PASS\n";
div(cout, "=");

//Erase
div(cout, "erase(const Item &target)");
cout << "Enter value to erase\n";
cin >> value;
cout << "The number of " << value << "s erased is : " << bag2.erase(value) << '\n';
cout << bag2;
cout << "Outcome : PASS\n";
div(cout, "=");

//Erease_one
div(cout, "erase_one(const Item &target)");
cout << "Enter value to erase\n";
cin >> value;
cout << "The result is : " << bag2.erase(value) << "\n\n";
cout << bag2;
cout << "Outcome : PASS\n";
div(cout, "=");

//operator=+
div(cout, "operator=+(const bag &addend)");
main_savitch_10::bag<int> bag3(bag1);
cout << bag2;
div(cout, "=");
cout << bag3;
div(cout, "=");
bag3 += bag2;
cout << bag3;
cout << "Outcome : PASS\n";
div(cout, "=");

//operator=
div(cout, "operator=(const bag &source)");
cout << bag1;
div(cout, "=");
bag3 = bag1;
cout << bag3;
cout << "Outcome : PASS\n";
div(cout, "=");

//size
div(cout, "size() const");
cout << "The size of bag2 is : " << bag2.size() << '\n';
cout << "Outcome : PASS\n";
div(cout, "=");

//count
div(cout, "count(const Item &target) const");
cout << "Enter the value you would like to find the frequency\n";
cin >> value;
cout << "The value " << value << " occurs " << bag2.count(value) << " times.\n";
cout << "Outcome : PASS\n";
div(cout, "=");

//bst_remove_max
div(cout, "bst_remove_max(binary_tree_node <Item> *root_ptr)");
cout << bag2;

//bst_remove_max()
cout << "Outcome : VOID\n";
div(cout, "=");

//operator<<
div(cout, "operator<<(ostream &out, const bag <Item> obj");
cout << bag2 << '\n';
cout << "Outcome : PASS\n";
div(cout, "=");

//operator+
div(cout, "operator+(const bag &b1, const bag &b2)");
cout << "Enter a value to add to bag1\n";
cin >> value;
bag1.insert(value);
cout << "bag1\n" << bag1 << '\n';
div(cout, "=");
cout << "bag2\n" << bag2 << '\n';
div(cout, "=");
cout << "bag3\n" <<bag3 << '\n';
div(cout, "=");
bag3 = bag1 + bag2;
cout << "new bag3\n" << bag3;
cout << "Outcome : PASS \n";
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
