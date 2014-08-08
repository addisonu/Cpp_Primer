//Project 7 : Part A
//FILE : application.cpp
//DESC : Base class for LendItem class automated record keeping system
//LEFT OFF: Problems with dynamic memory(4,8), error: segmentation fault 11
#include <iostream>
#include <string>
#include "LendItem.h"
#include "DVD.h"
#include "Book.h"
#include <new>
#include <stdlib.h>

int main()
{
//Pointer to array of pointers of type Lend Item; Both Book and DVD
    LendItem **LendArr;

//Variable for various types of user input from menu
    char ch_choice('u');
    std::string str_choice(" ");

    do{

        std::cout << std::endl <<
            "q  : To quit\n"
            "0  : Enter a new Book\n"
            "1  : Enter a new DVD\n"
            "2  : Borrow book\n"
            "3  : Borrow DVD\n"
            "4  : Print out title and status of all Books owned\n"
            "5  : Print out title and status of all DVDs owned\n"
            "6  : Check if item is owned by Marina and print borrow status\n"
            "7  : Print all information on specific title\n"
            "8  : Print out all titles by author\n"
            "9  : Output name of all owned checked out items\n"
        << std::endl;

        std::getline(std::cin, str_choice);
        ch_choice = str_choice[0];

        if(ch_choice != 'q'){
            ch_choice = ch_choice - '0';
        }

        switch(ch_choice)
        {
//Enter a new Book
            case 0:
            {
                LendItem::LI_size++;
                LendItem ** tmp = new LendItem *[LendItem::LI_size];
                for(int n = 0; n < LendItem::LI_size - 1; n++){
                    tmp[n] = LendArr[n];
                }
                delete[] LendArr;
                LendArr = tmp;

                std::cout << "Do you want to enter a default entry or an entry with specific information? Enter 'd' for default or 's' for specific." << std::endl;

                std::getline(std::cin, str_choice);
                ch_choice = str_choice[0];

                if(ch_choice == 'd'){
                    LendArr[LendItem::LI_size - 1] = new Book();
                }
                else if (ch_choice == 's'){
                    std::cout << "Enter the title of the new Book." << std::endl;
                    std::string title(" ");
                    std::getline(std::cin, title);

                    std::cout << "Enter the author of the new Book." << std::endl;
                    std::string author(" ");
                    std::getline(std::cin, author);

                    std::cout << "Enter the cover type of the new Book." << std::endl;
                    char covtyp(' ');
                    std::getline(std::cin, str_choice);
                    covtyp = str_choice[0];

                    LendArr[LendItem::LI_size - 1] = new Book(title, author, covtyp);
                }
                std::cout << "New Book created." << std::endl;
            }
                break;
//Enter a new DVD
            case 1:
            {
                LendItem::LI_size++;
                LendItem ** tmp = new LendItem *[LendItem::LI_size];
                for(int n = 0; n < LendItem::LI_size - 1; n++){
                    tmp[n] = LendArr[n];
                }
                delete[] LendArr;
                LendArr = tmp;

                std::cout << "Do you want to enter a default entry or an entry with specific information? Enter 'd' for default or 's' for specific." << std::endl;

                std::getline(std::cin, str_choice);
                ch_choice = str_choice[0];

                if(ch_choice == 'd'){
                    LendArr[LendItem::LI_size - 1] = new DVD();
                }
                else if (ch_choice == 's'){
                    std::cout << "Enter the title of the new DVD." << std::endl;
                    std::string title(" ");
                    std::getline(std::cin, title);

                    std::cout << "Enter the rating of the new DVD." << std::endl;
                    std::string rating(" ");
                    std::getline(std::cin, rating);

                    std::cout << "Enter the screen type of the new DVD." << std::endl;
                    char screentyp(' ');
                    std::getline(std::cin, str_choice);
                    screentyp = str_choice[0];

                    LendArr[LendItem::LI_size - 1] = new DVD(title, rating, screentyp);
                }

                std::cout << "New DVD created." << std::endl;
            }
                break;
//Borrow book
            case 2:
            {
                if(LendItem::LI_size > 0){
                    std::cout << "Enter the title of book you would like to borrow." << std::endl;
                    std::getline(std::cin, str_choice);

//Search through catalogue of Marina items
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getTitle() == str_choice && !LendArr[n]->getBorrowed() && LendArr[n]->getMedium() == 'B'){
                            LendArr[n]->setBorrowed(true);
                            std::cout << "\nThe book has been borrowed" << std::endl;
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "The title you entered is either borrowed or doesn't exist" << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Borrow DVD
            case 3:
            {
                if(LendItem::LI_size > 0){
                    std::cout << "Enter the title of DVD you would like to borrow." << std::endl;
                    std::getline(std::cin, str_choice);

//Search through catalogue of Marina items
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getTitle() == str_choice && !LendArr[n]->getBorrowed() && LendArr[n]->getMedium() == 'D'){
                            LendArr[n]->setBorrowed(true);
                            std::cout << "The DVD has been borrowed." << std::endl;
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "The title you entered is either borrowed or doesn't exist" << std::endl;
                        }
                    }
                }
                else{
                     std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Print out title and status of all Books owned
            case 4:
            {
                if(LendItem::LI_size > 0){
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getMedium() == 'B'){
                            dynamic_cast<Book*>(LendArr[n])->printAll(std::cout, LendArr);
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "There aren't currently any Book titles at Marina." << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Print out title and status of all DVDs owned
            case 5:
            {
                if(LendItem::LI_size > 0){
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getMedium() == 'D'){
                            dynamic_cast<DVD*>(LendArr[n])->printAll(std::cout, LendArr);
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "There aren't currently any DVD titles at Marina." << std::endl;
                        }
                    }
                }
                 else{
                     std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Check if item is owned by Marina and print borrow status
            case 6:
            {
                if(LendItem::LI_size > 0){
                    std::cout << "Enter the title of the book or DVD you would like to search for." << std::endl;
                    std::getline(std::cin, str_choice);

//Search for item in array
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getTitle() == str_choice){
                            std::cout << *LendArr[n];
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "The title you entered is either borrowed or doesn't exist" << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Print all information on specific title
            case 7:
            {
                if(LendItem::LI_size > 0){
                    std::cout << "Enter the title of the book or DVD you would like to search for." << std::endl;
                    std::getline(std::cin, str_choice);

//Search for item in array
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getTitle() == str_choice){
                            if(LendArr[n]->getMedium() == 'B'){
                                std::cout << std::endl << *LendArr[n] << " - " << dynamic_cast<Book*>(LendArr[n])->getAuth() << " - " << dynamic_cast<Book*>(LendArr[n])->getCover() << std::endl;
                            }
                            else if(LendArr[n]->getMedium() == 'D'){
                                std::cout << std::endl << *LendArr[n] << " - " << dynamic_cast<DVD*>(LendArr[n])->getRate() <<  " - " << dynamic_cast<DVD*>(LendArr[n])->getType() << std::endl;
                            }
                                break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "The title you entered is either borrowed or doesn't exist" << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Print out all titles by author
            case 8:
            {
                int cnt(0);

                if(LendItem::LI_size > 0){
                    std::cout << "Enter the author you would like to list all Book and DVD titles for." << std::endl;
                    std::getline(std::cin, str_choice);

//Search for item in array
                        for(int n = 0; n < LendItem::LI_size; n++){
                            if(dynamic_cast<Book*>(LendArr[n])->getAuth() == str_choice){
                                std::cout << LendArr[n]->getTitle() << std::endl;
                                cnt++;
                            }
                            else if(n == (LendItem::LI_size - 1) && cnt == 0){
                                std::cout << "There are no titles by the author that you entered" << std::endl;
                            }
                        }
                }
                else
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
//Output name of all owned checked out items
            case 9:
            {
                int cnt(0);

                if(LendItem::LI_size > 0){

//Search for item in array
                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(LendArr[n]->getBorrowed()){
                            std::cout << "Borrowed : " << LendArr[n]->getTitle() << std::endl;
                            cnt++;
                        }
                        else if(n == (LendItem::LI_size - 1) && cnt == 0){
                            std::cout << "There are no borrowed titles" << std::endl;
                        }
                    }
                }
                else{
                    std::cout << "There aren't any books or DVDs on file. Choose the appropriate menu option to add items to the database." << std::endl;
                }
            }
                break;
    }
}while(ch_choice != 'q');
    return 0;
}

