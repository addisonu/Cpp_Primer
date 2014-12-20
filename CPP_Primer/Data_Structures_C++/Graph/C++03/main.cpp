//DATE: 12/08/14
//ASSIGNMENT: Project 8
//FILE: main.cpp
//DESC: Unit tests for EdgeNode and Graph classes

#include <string>
#include <iostream>
#include "EdgeNode.h"
#include "Graph.h"

void div(std::string label = "=", char outcome = 'N');

int main()
{
std::cout << std::boolalpha;

// EdgeNode //
div("EdgeNode(vnum)", 'P');
EdgeNode e1(7);
std::cout << e1.getvnum() << std::endl;

div("setvnum(vnum)", 'P');
e1.setvnum(8);
std::cout << e1.getvnum() << std::endl;

div("getvnum()", 'P');
std::cout << e1.getvnum() << std::endl;

div("operator==(EdgeNode)", 'P');
EdgeNode e2(9), e3(8);
std::cout << "e1==e2 : " << (e1 == e2) << std::endl;
std::cout << "e1==e3 : " << (e1 == e3) << std::endl;

// Graph //

div("Graph()", 'P');
Graph<std::string> g1;
std::cout << g1.size() << std::endl;

div("add_vertex(label)", 'P');
std::size_t v1 = 0, v2 = 1, v3 = 2, v4 = 3, v5 = 4, v6 = 5;
std::string label1 = "one", label2 = "two", label3 = "three", label4 = "four", label5 = "five", label6 = "six";
g1.add_vertex(label1);
g1.add_vertex(label2);
g1.add_vertex(label3);
g1.add_vertex(label4);
g1.add_vertex(label5);
g1.add_vertex(label6);

std::cout << "g1[v1] = " << g1[v1] << std::endl;
std::cout << "g1[v2] = " << g1[v2] << std::endl;

div("add_edge(source, target)", 'P');
g1.add_edge(v1, v2);
std::cout << "Was it added? " << g1.is_edge(v1, v2) << std::endl;

div("remove_edge(source, target)", 'P');
g1.remove_edge(v1, v2);
std::cout << "Was it removed? " << g1.is_edge(v1, v2) << std::endl;

div("operator[](vertex)", 'P');
std::cout << "g1[v1] = " << g1[v1] << std::endl;

div("size()", 'P');
std::cout << "size of g1 : " << g1.size() << std::endl;

div("is_edge(source, target)", 'P');
g1.add_edge(v1, v6);
std::cout << "v1--------v2 is an edge? " << g1.is_edge(v1, v2) << std::endl;

div("neighbors(vertex)", 'P');
g1.add_edge(v1, v4);
g1.add_edge(v4, v3);
g1.add_edge(v3, v5);
std::set<std::size_t> neighbors = g1.neighbors(v1);

for(std::set<std::size_t>::iterator i = neighbors.begin(); i != neighbors.end(); ++i)
    std::cout << *i << ", ";
std::cout << std::endl;

div("operator[](const vertex)", 'P');
std::cout << "g1[v2] = " << g1[v2] << std::endl;

div("pos(label)");
std::cout << "pos of two: " << g1.pos("two") << std::endl;

div("is_path(source, target)");
std::cout << "there is a path from v1 to v5: \n" << g1.is_path(v1, v5) << std::endl;
std::cout << "path from v1 to v6 : \n" << g1.is_path(g1.pos(label1), g1.pos(label6)) << std::endl;
std::cout << "there is a path from v1 to v6: \n" << g1.is_path(v1, v6) << std::endl;
std::cout << "path from v1 to v2 : \n" << g1.is_path(g1.pos(label1), g1.pos(label2)) << std::endl;

    return 0;
}
void div(std::string label, char outcome)
{
    if(label == "=")
        std::cout << std::string(30, '=') << std::endl;
    else
        std::cout << std::string(30, '=') << std::endl << label << " : " << outcome << std::endl << std::string(30, '=') << std::endl;
}
