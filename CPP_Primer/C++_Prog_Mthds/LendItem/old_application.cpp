//Project 7 : Part A
//FILE : Function to test LendItem, Book, and DVD classes
//DESC : main.cpp
//LEFT OFF: Doesn't compile, problems with dynamic memory

#include <iostream>
#include <string>
#include "LendItem.h"
#include "DVD.h"
#include "Book.h"
#include <new>
#include <stdlib.h>

void update_LIarr(LendItem **Lendarr, char med);

int main()
{
//Test LendItem class
    LendItem **Lendarr = new LendItem*[LendItem::LI_capacity];
    LendItem::LI_size = 2;
    Lendarr[0] = new DVD();
    Lendarr[1] = new Book();
    std::string tle(" ");

//Variable to allow user to continue or exit program

int choice(10);

    while(choice != -1)
    {
        std::cout << std::endl <<
            "-1 : To quit enter 0\n"
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

//Get user menu choice
/*       while(true){
            std::cout << "Enter your choice from the menu." << std::endl;
            std::getline(std::cin, tle);

            if(isdigit(tle[0]) || (atoi(tle[0]) == -1)){
                choice = atoi(tle[0]);
                break;
            }
            std::cout << "You've entered invalid input." << std::endl;
        }
*/
        std::cout << "Enter choice from menu.\n";
        std::cin >> choice;
        switch(choice)
        {
//Enter a new Book
            case 0:
            {
                Lendarr[LendItem::LI_size] = new Book();
                std::cout << *Lendarr[LendItem::LI_size];
                LendItem::LI_size++;
                //update_LIarr(Lendarr, 'B');
            }
                break;

//Enter a new DVD
            case 1:
            {
                Lendarr[LendItem::LI_size] = new DVD();
                std::cout << *Lendarr[LendItem::LI_size];
                LendItem::LI_size++;
                //update_LIarr(Lendarr, 'D');
            }
                break;

//Borrow book
            case 2:
            {
                std::cout << "\nEnter the title of the book you would like to borrow." << std::endl;
                std::getline(std::cin, tle);

                for(int n = 0; n < LendItem::LI_size; n++){
                    if((Lendarr[n]->getTitle() == tle) && !(Lendarr[n]->getBorrowed())){
                        dynamic_cast<Book*>(Lendarr[n])->setBorrowed(true);
                    }
                    else if(n == (LendItem::LI_size - 1)){
                        std::cout << "This title is currently borrowed or doesn't exist." << std::endl;
                    }
                }
            }
                break;

//Borrow DVD
            case 3:
            {
                std::cout << "\nEnter the title of the DVD you would like to borrow." << std::endl;
                std::getline(std::cin, tle);

                for(int n = 0; n < LendItem::LI_size; n++){
                    if((Lendarr[n]->getTitle() == tle) && !Lendarr[n]->getBorrowed()){
                        dynamic_cast<DVD*>(Lendarr[n])->setBorrowed(true);
                    }
                    else if(n == (LendItem::LI_size - 1)){
                        std::cout << "This title is currently borrowed or doesn't exist." << std::endl;
                    }
                }
            }
                break;

//Print out title and status of all Books owned
            case 4:
            {
                dynamic_cast<Book*>(Lendarr[1])->printAll(std::cout, Lendarr);
            }
                break;
//Print out title and status of all DVDs owned
            case 5:
            {
                    dynamic_cast<DVD*>(Lendarr[0])->printAll(std::cout, Lendarr);
            }
                break;

//Check if item is owned by Marina and print borrow status
            case 6:
            {
                std::cout << "Enter the title of the book or DVD to check.";
                std::getline(std::cin, tle);

                for(int n = 0; n < LendItem::LI_size; n++){
                    if(Lendarr[n]->getTitle() == tle){
                        std::cout << "Item borrowed : " << Lendarr[n]->getBorrowed() << std::endl;
                        break;
                    }
                    else if(n == (LendItem::LI_size - 1)){
                        std::cout << "The title you entered doesn't exist." << std::endl;
                    }
                }
            }
                break;

//Print all information on specific title
            case 7:
            {
                    std::cout << "Enter the title of the book or DVD to print all information for.";
                    std::getline(std::cin, tle);

                    for(int n = 0; n < LendItem::LI_size; n++){
                        if(Lendarr[n]->getTitle() == tle){

                            std::cout << "Title : " << Lendarr[n]->getTitle() << std::endl;
                            std::cout << "Medium : " << Lendarr[n]->getMedium() << std::endl;
                            std::cout << "BNumber : " << Lendarr[n]->getBNumber() << std::endl;
                            std::cout << "Borrowed status : " << Lendarr[n]->getBorrowed() << std::endl; 

                            if(Lendarr[n]->getMedium() == 'B'){
                                std::cout << "Cover : " << dynamic_cast<Book*>(Lendarr[n])->getCover() << std::endl;
                                std::cout << "Author : " << dynamic_cast<Book*>(Lendarr[n])->getAuth() << std::endl;
                            }
                            else if(Lendarr[n]->getMedium() == 'D'){
                                std::cout << "Cover : " << dynamic_cast<DVD*>(Lendarr[n])->getType() << std::endl;
                                std::cout << "Cover : " << dynamic_cast<DVD*>(Lendarr[n])->getRate() << std::endl;
                            }
                            break;
                        }
                        else if(n == (LendItem::LI_size - 1)){
                            std::cout << "The title you entered doesn't exist." << std::endl;
                        }
                    }
            }
                break;

//Print out all titles by author
            case 8:
            {
                std::cout << "Enter the author of the book or DVD to print all information for.";
                std::getline(std::cin, tle);

                for(int n = 0; n < LendItem::LI_size; n++){
                    if(dynamic_cast<Book*>(Lendarr[n])->getAuth() == tle){

                        std::cout << "Title : " << Lendarr[n]->getTitle() << std::endl;
                        std::cout << "Medium : " << Lendarr[n]->getMedium() << std::endl;
                        std::cout << "BNumber : " << Lendarr[n]->getBNumber() << std::endl;
                        std::cout << "Borrowed status : " << Lendarr[n]->getBorrowed() << std::endl;

                        if(Lendarr[n]->getMedium() == 'B'){
                            std::cout << "Cover : " << dynamic_cast<Book*>(Lendarr[n])->getCover() << std::endl;
                            std::cout << "Author : " << dynamic_cast<Book*>(Lendarr[n])->getAuth() << std::endl;
                        }
                        else if(Lendarr[n]->getMedium() == 'D'){
                            std::cout << "Cover : " << dynamic_cast<DVD*>(Lendarr[n])->getType() << std::endl;
                            std::cout << "Cover : " << dynamic_cast<DVD*>(Lendarr[n])->getRate() << std::endl;
                        }
                        break;
                    }
                    else if(n == (LendItem::LI_size - 1)){
                        std::cout << "The author you entered doesn't exist." << std::endl;
                    }
                }
            }
                break;

//Output name of all owned checked out items
            case 9:
            {
                for(int n = 0; n < LendItem::LI_size; n++){
                    if(Lendarr[n]->getBorrowed()){
                        std::cout << Lendarr[n]->getTitle() << std::endl;
                    }
                }
            }
                break;
        }
    }
/*
    for(int n = 0; n < LendItem::LI_size; n++){
        delete[] Lendarr[n];
    }
    delete[] Lendarr;
*/
    return 0;
}

void update_LIarr(LendItem **Lendarr, char med)
{
    std::string tle(" ");
    char choice(-1);

    if(LendItem::LI_size == (LendItem::LI_capacity - LendItem::LI_size)){
        LendItem ** tmp = new LendItem*[2*(LendItem::LI_capacity)];

        for(int n = 0; n < (2*(LendItem::LI_capacity)); n++){
            tmp[n] = Lendarr[n];
        }
        delete[] Lendarr;
        LendItem::LI_capacity *= 2;
        Lendarr = tmp;
    }
    if(med == 'B'){
        std::cout << "Do you want to enter a default Book or a book with values? Enter 0 for a default Book and 1 for Book with values." << std::endl;
        if(choice == '1'){
            std::cout << "Enter the Book title, author, and cover type separating each entry by a space." << std::endl;
            std::getline(std::cin, tle);

            int pos(0);
            std::string title = tle.substr(0, (pos = tle.find_first_of(" ") - 1));
            int secpos = tle.find_first_of(" ", pos + 1);
            std::string auth = tle.substr((pos + 1), secpos - pos - 1);
            char cover = tle[secpos + 1];

            Lendarr[LendItem::LI_size - 1] = new Book(title, auth, cover);
        }
        else if(choice == '0'){
            Lendarr[LendItem::LI_size - 1] = new Book();
        }
    }
    else if(med == 'D'){
        std::cout << "Do you want to enter a default DVD or a DVD with values? Enter 0 for a default DVD and 1 for DVD with values." << std::endl;
        if(choice == '1'){
            std::cout << "Enter the DVD title, author, and cover type separating each entry by a space." << std::endl;
            std::getline(std::cin, tle);

            int pos(0);
            std::string title = tle.substr(0, (pos = tle.find_first_of(" ") - 1));
            int secpos = tle.find_first_of(" ", pos + 1);
            std::string rating = tle.substr((pos + 1), secpos - pos - 1);
            char stype = tle[secpos + 1];

            Lendarr[LendItem::LI_size - 1] = new DVD(title, rating, stype);
        }
        else if(choice == '0'){
            Lendarr[LendItem::LI_size - 1] = new DVD();
        }
    }
    LendItem::LI_size++;
}
