//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: main.cpp
//DESC: Unit tests for heap and patient classes



#include <iostream>
#include <string>
#include <stdexcept>
#include <algorithm>
#include "heap.h"
#include "patient.h"

using std::cout;
using std::cin;
using std::endl;
using std::string;

void div(string label = "=", char outcome = 'N');

int main()
{
cout << std::boolalpha;
////////////////////
// Tests for Patient class
////////////////////
div("Default constructor Patient(name, malady, priority)", 'P');
div();
Patient p1("Jane Doe", "Measles", 1);
Patient p3("Sylvia Stone", "Anxiety", 3);
Patient p5("Kilian Jones", "Edema", 5);
Patient p4("Edamame Frapp", "Bunions", 4);
Patient p2("Stevie Wonder", "Rotator Cuff Fracture", 2);
////////////////////
div("get_name()", 'P');
cout << p1.get_name() << endl;
////////////////////
div("get_malady", 'P');
cout << p1.get_malady() << endl;
////////////////////
div("get_priority", 'P');
cout << p1.get_priority() << endl;
////////////////////
div("operator==", 'P');
cout << p1 << endl;
cout << p2 << endl;
cout << "p1 == p2 : " << (p1 == p2) << endl;
////////////////////
div("operator<", 'P');
cout << p1 << endl;
cout << p2 << endl;
cout << "p1<p2 : " << (p1 < p2) << endl;
////////////////////
div("operator>", 'P');
cout << p1 << endl;
cout << p2 << endl;
cout << "p1>p2 : " << (p1 > p2) << endl;
////////////////////
//Tests for Heap class
////////////////////
div("Default constructor Heap(int)", 'P');
Heap<Patient> h1(5);
////////////////////
div("operator=", 'P');
Heap<Patient> h2(2);
//h2 = h1;
cout << h2 << endl;
////////////////////
div("IsEmpty()", 'P');
cout << "h1.IsEmpty() : " << h1.IsEmpty() << endl;
////////////////////
div("IsFull()", 'P');
cout << "h2.IsFull() : " << h2.IsFull() << endl;
////////////////////
div("add", 'P');
int item(7);
cout << "h2 : " << h2 << endl;
try{
h2.add(p1);
h2.add(p3);
h2.add(p4);
h2.add(p2);
h2.add(p5);
}
catch(const fullpq &e){
    std::cerr << e.what() << endl;
}
cout << "h2 : " << h2 << endl;
////////////////////
div("remove");
Patient removed;
h2.remove(removed);
//h2.remove(removed);
cout << "h2 : " << h2 << endl;
cout << "item = " << removed << endl;
////////////////////
    return 0;
}

void div(string label, char outcome)
{
    if(label == "=")
        cout << string(30, '=') << endl;
    else
        cout << string(30, '=') << endl << label << " : " << outcome << endl << string(30, '=') << endl;
}
