//AUTHOR: NA
//DATE: 11/12/17
//FILE: main.cpp
//DESC: Driver for building decision tree

#include <vector>
#include <string>
#include <set>
#include <iostream>
#include "ToyDecisionTree.h"
#include "TestToyDecisionTree.h"

int main(int argc, char **argv)
{
    TestToyDecisionTree ttdt;
    //ttdt.Test_initialize_network();
    //ttdt.Test_activate();
    //ttdt.Test_transfer();
    //ttdt.Test_foward_propagate();
    //ttdt.Test_transfer_derivative();
    //ttdt.Test_backward_propagate_error();
    ttdt.Test_train_network();
}
