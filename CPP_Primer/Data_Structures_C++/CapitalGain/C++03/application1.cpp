//10/16/14
//Project 4
//application.cpp
//Application source file that makes use of the Queue template and Transaction classes

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include <cstdlib>
#include "Transaction.h"
#include "QueueT.h"

using std::cout;
using std::cin;
using std::string;
using std::endl;

int main()
{
//Variables to hold user input
    string input, choice;
    int quantity(0), vendorID(0);
    double price(0), profit(0);

//List to hold company names
    std::list<string> names;

//List of Queues to hold companies
    std::list<Queue<Transaction> > companies;

//User can use the program until they choose to terminate
do{

//Register a company name with the program//
    cout << "Would you like to register a company with the application?\n";
    std::getline(cin, choice);
    if(choice == "y"){
        cout << "Please enter the name of the company to register. A vendorID will be returned." << endl;

//Get the company name from user
        std::getline(cin, input);
        names.push_back(input);

//Create new Queue to hold company transactions
        Queue<Transaction> new_company(0);

//Add Queue to companies list
        companies.push_back(new_company);

//Display assigned vendorID
        cout <<"The vendorID for " << input << " is " << (companies.size() - 1)  << endl;
    }
//Buy a stock: provide price, quantity, and vendorID//
    cout << "Would you like to buy stock?\n";
    std::getline(cin, choice);
    if(choice == "y" && names.size()){

//Prompt user for the price, quantity, and vendorID in that order
        cout << "Enter the price, quantity, and vendorID for the transaction.\n";

//Read user input into transaction variables
        size_t pos0(0), pos1(0);
        std::getline(cin, input);
        price = atof(input.substr(0, pos0 = input.find_first_of(" ")).c_str());
        quantity = atoi(input.substr(pos0 + 1, pos1 = input.find_first_of(" ", pos0 + 1)).c_str());
        vendorID = atoi(input.substr(pos1 + 1, input.find_first_of(" ", pos1 + 1)).c_str());

//Create transaction
        Transaction buy(price, quantity, vendorID);

//Add transaction to the company Queue with iterator to company Queue
         std::list<Queue<Transaction> >::iterator trans = companies.begin();

        if(vendorID > 0)
            for(int i = 1; i <= vendorID;i++)
                trans++;
        trans->add(buy);
    }
    else if(choice == "y" && !names.size()){
        cout << "You must register a company before buying stock." << endl;
    }
//Sell a stock: provide the price, quantity, vendorID//
    cout << "Would you like to sell stock?\n";
    std::getline(cin, choice);

//Check that there is at least one transaction on file
    std::list<Queue<Transaction> >::iterator  check = companies.begin();
    std::list<Queue<Transaction> >::iterator sell;

    if(choice == "y" && ((names.size() == 1 && check->first().getQuan()) || names.size() > 1) ){
        cout << "Enter the price, quantity, and vendorID for the transaction.\n";

//Create variables used to process stock sell
        size_t pos0(0), pos1(0);
//Read user input into sell_price, sell_quantity, and sell_vendorID
        std::getline(cin, input);

        double sell_price = atof(input.substr(0, pos0 = input.find_first_of(" ")).c_str());
        int sell_quantity = atoi(input.substr(pos0 + 1, pos1 = input.find_first_of(" ", pos0 + 1)).c_str());
        int sell_vendorID = atoi(input.substr(pos1 + 1, input.find_first_of(" ", pos1 + 1)).c_str());

        sell = companies.begin();

        if(vendorID > 0)
            for(int i = 1; i <= vendorID; i++)
                sell++;

//Calculate profit from selling shares
        do{

//Get values associated with first transaction in queue
            Transaction oldest_trans = sell->first();

            if(oldest_trans.getQuan() <= sell_quantity){
                profit += (oldest_trans.getQuan())*(sell_price - oldest_trans.getPrice());
                sell_quantity -= oldest_trans.getQuan();
                sell->remove();
            }
            else{
                profit += sell_quantity*(sell_price - oldest_trans.getPrice());
                std::list<Transaction>::iterator oldest = sell->begin();
                oldest->setQuan(oldest_trans.getQuan() - sell_quantity);
                sell_quantity = 0;
            }
//Check that there is at least one transaction on file
        }while(sell_quantity > 0 && sell->size());
        cout << "Your profit is : " << profit << endl;
    }
    else if(choice == "y" && (!names.size() || !check->first().getQuan())){
        cout << "To sell a stock, at least one company must be registered with at least one transaction." << endl;
    }

//Print all stock for a specifice vendor: provide vendorID//
    cout << "Would you like to print all transaction information for a particular stock?\n";
    std::getline(cin, choice);
    if(choice == "y"){

//Prompt user for company vendorID
    cout << "Enter the vendorID for the company stock information you would like to print.\n";

//Read user input into variable
    std::getline(cin, input);
    vendorID = atoi(input.c_str());

//Create iterator for company Queue
    std::list<Queue<Transaction> >::iterator display = companies.begin();

    if(vendorID > 0)
        for(int i = 1; i <= vendorID; i++)
        display++;

//Call overloaded operator<< on company Queue
    cout << *display;
    }
//Find the name a company: provide vendorID//
    cout << "Would you like to look up the name of a company?\n";
    std::getline(cin, choice);
    if(choice == "y" && names.size()){

//Prompt user for vendorID
        cout << "Enter the vendorID for the company name you would like to display.\n";

//Read input and store into vendorID
        std::getline(cin, input);
        vendorID = atoi(input.c_str());

//Create iterator for names list
        std::list<string>::iterator company_name = names.begin();

        if(vendorID > 0)
            for(int i = 1; i <= vendorID; i++)
                company_name++;

//Display company name
        cout << "The company name for the given vendorID is " << *company_name << endl;
    }
    else if(choice == "y" && !names.size()){
        cout << "You must register a company before buying stock." << endl;
    }
    cout << "Would you like to continue using the progam? Enter 'y' to continue and 'n' to exit.\n";
    std::getline(cin, choice);
}while(choice != "n");
    return 0;
}
