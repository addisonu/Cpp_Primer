//DATE: 12/08/16
//ASSIGNMENT: Project 8
//FILE: graph.h
//DESC: Definition of template class graph. A graph object is an edge list implementation of a labeled graph with a fixed number of vertices and labels of type Item

#ifndef GRAPH_H
#define GRAPH_H

#include <cstddef>
#include <list>
#include <set>
#include <stdexcept>
#include <algorithm>
#include <cassert>
#include <queue>
#include "EdgeNode.h"


template <typename Item> class Graph{

public:

// MEMBER CONSTANTS //

//Graph::MAXIMUM is the maximum number of vertices that a graph can have
    static const size_t MAXIMUM;

// CONSTRUCTOR //

//Postcondition: The graph has been initialized with no vertices and no edges
    Graph();

// NONCONSTANT MEMBER FUCTIONS //

//Precondition: size() < MAXIMUM
//Postcondition: The size of the graph has been increased by adding one new vertex. This new vertex has the specified label and no edges
    void add_vertex(const Item &label);

//Precondition: source < size() && target < size()
//Postcondition: The graph has all the edges that it originally had, and it has another edge from the specified source to the specified target (If this edge was already present, then the graph is unchanged)
    void add_edge(size_t source, size_t target);

//Precondition: source < size() and target < size()
//Postcondition: The graph has all the edges that it originally had except for the edge from the specified source to the specified target (If this edge was not originally present, then the graph is unchanged)
    void remove_edge(size_t source, size_t target);

//Precondition: vertex < size()
//Postcondition: The return value is a reference to the label of the specified vertex
    Item& operator[](size_t vertex);

// CONSTANT MEMBER FUNCTIONS //

//Postcondition: The return value is the number of vertices in the graph
    size_t size() const;

//Precondtion: source < size() && target < size()
//Postcondition: The return value is true if the graph has an edge from source to target. Otherwise the return value is false
    bool is_edge(const size_t source, const size_t target) const;

//Precondition: vertex < size()
//Postcondition: The return value is a set that contains all the vertex numbers of vertices that are the target of an edge whose source is at the specified vertex
    std::set<size_t> neighbors(size_t vertex) const;

//Precondtion: vertex < size()
//Postcondition: The return value is a reference to the label of the specified vertex
    Item operator[](size_t vertex) const;

//Precondition: source <size() && target < size() using breadthfirst search algorithm
//Postconditon: The return value is true if the graph has a path from source to target. Otherwise the return value is false
    bool is_path(size_t source, size_t target) const;

//Postcondition: The return value is the position of the vertex information in the arrays vertexlist and edges. If the label doesn't exist, error message is displayed and -1 is returned.
    int pos(Item label);

private:

// DATA MEMBERS //

    Item vertexlist[MAXIMUM]; //array which stores Vertex lables
    std::list<EdgeNode> edges[MAXIMUM]; // array which stores an edge list for each vertex
    size_t many_vertices; //number of Vertex nodes currently stored
};
template <typename Item> const size_t Graph<Item>::MAXIMUM = 100;

#include "Graph.cpp"
#endif
