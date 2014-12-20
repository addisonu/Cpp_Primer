//DATE: 12/08/14
//ASSIGNMENT: Project 8
//FILE: application.cpp
//DESC: Will use a Graph<string> object for storing the courses and their relationships. Users will be able to see what the prerequisites are for a given course

#include <iostream>
#include <string>
#include "Graph.h"

int main()
{
//Variables for user input
    std::string input("n"), source, target;
    unsigned menu(7);
    Graph<std::string> graph;

//Program will continue until user quits
    do{

//Menu of options
    std::cout << "\n\nThis program can perform the following menu options. Enter the corresponding menu number to execute your choice.\n\n"
        << " 0 : Enter a new course\n"
        << " 1 : Enter a prerequisite relationship between two courses\n"
        << " 2 : Remove a prerequisite relationship between two courses\n"
        << " 3 : Report if one course is the immediate prerequisite of another course\n"
        << " 4 : Report if there is a prerequisite path between one course and another course\n"
        << " 5 : Output all courses which can be taken directly after taking a specific course\n"
        << " 6 : Output all courses which have been entered\n\n";

//Read user menu choice
    std::getline(std::cin, input);

//Make sure user enters option
    if(!input.size())
        menu = 7;
    else
        menu = atoi(input.substr(0,1).c_str());

//switch statement to execute chosen option

    switch(menu){
//Enter a new course
        case 0:
            {
//Prompt user for course name
                std::cout << "Enter the new course name.\n";
                std::getline(std::cin, input);
                graph.add_vertex(input);
            }
              break;

//Enter a prerequisite relationship between two courses
        case 1:
            {
//Prompt user for course names
                std::cout << "Enter the prerequisite course name.\n";
                std::getline(std::cin, source);

                std::cout << "Enter the dependent course name.\n";
                std::getline(std::cin, target);

//Convert course names to array positions and create path between them
                try{
                    graph.add_edge(graph.pos(source), graph.pos(target));
                }
                catch(const std::out_of_range &e){
                    std::cerr << e.what() << std::endl;
                    break;
                }
            }
              break;

//Remove a prerequisite relationship between two courses
        case 2:
            {
//Prompt user for course names
                std::cout << "Enter the prerequisite course name.\n";
                std::getline(std::cin, source);

                std::cout << "Enter the dependent course name.\n";
                std::getline(std::cin, target);

//Convert course names to array positions and destroy path between them
                try{
                    graph.remove_edge(graph.pos(source), graph.pos(target));
                }
                catch(const std::out_of_range &e){
                    std::cerr << e.what() << std::endl;
                    break;
                }
            }
              break;

//Report if one course is the immediate prerequisite of another course
        case 3:
            {
//Prompt user for course names
                std::cout << "Enter the possible prerequisite course name.\n";
                std::getline(std::cin, source);

                std::cout << "Enter the possible dependent course name.\n";
                std::getline(std::cin, target);
                bool found(false);

//Convert course name to array position and search for it in edges list
                try{
                    found = graph.is_edge(graph.pos(source), graph.pos(target));
                }
                catch(const std::out_of_range &e){
                    std::cerr << e.what() << std::endl;
                    break;
                }
//Print result of search
                if(found)
                    std::cout << source << " is a prerequisite course of " << target << "." << std::endl;
                else
                    std::cout << source << " is not a prerequisite course of " << target << "." << std::endl;
            }
              break;

//Report if there is a prerequisite path between one course and another course
        case 4:
            {
//Prompt user for course names
                std::cout << "Enter the first course name.\n";
                std::getline(std::cin, source);

                std::cout << "Enter the second course name.\n";
                std::getline(std::cin, target);

//Invoke is_path() to check if there is a path between argument vertices
                bool found(false);
                try{
                    found = graph.is_path(graph.pos(source), graph.pos(target));
                }
                catch(const std::out_of_range &e){
                    std::cerr << e.what() << std::endl;
                    break;
                }
//Print result
                if(found)
                    std::cout << "There is a prerequisite path between the courses " << source << " and " << target << std::endl;
                else
                    std::cout << "There is not a prerequisite path between the courses " << source << " and " << target << std::endl;
            }
              break;

//Output all courses which can be taken directly after taking a specific course
        case 5:
            {
//Prompt user for prerequisite course name
                std::cout << "Enter the prerequisite course name.\n";
                std::getline(std::cin, source);

//Get all vertices that share an edge with prerequisite course
                std::set<std::size_t> vertices;
                try{
                    vertices = graph.neighbors(graph.pos(source));
                }
                catch(const std::out_of_range &e){
                    std::cerr << e.what() << std::endl;
                    break;
                }

//Print labels for all vertices
                std::cout << "Courses that can be taken after completing " << source << ":" << std::endl;
                for(std::set<std::size_t>::iterator i = vertices.begin(); i != vertices.end(); ++i)
                    std::cout << graph[*i] << std::endl;
            }
              break;

//Output all courses which have been entered
        case 6:
            {
//Loop through vertexlist and print lables
                for(unsigned i = 0; i!= graph.size(); ++i)
                    std::cout << graph[i] << std::endl;
            }
              break;

//Selection isn't on menu
        default:
            {
                std::cout << "Your selection isn't on the menu." << std::endl;
            }
    }
//Allow user to continue or terminate program
        std::cout << "\nDo you want to continue using the program? Enter 'n' to terminate, or any other key to continue.\n";
        std::getline(std::cin, input);
    }while(input[0] != 'n');

    return 0;
}
