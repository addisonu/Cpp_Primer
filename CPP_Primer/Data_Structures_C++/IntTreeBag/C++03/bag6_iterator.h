//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: bag6_iterator.h
//DSCR: Definition and implementation of iterator for bag class

#ifndef BAG6_ITERATOR_H
#define BAG6_ITERATOR_H

#include <iterator>

class binary_tree_node_iterator : public std::iterator<std::forward_iterator_tag, Item>{
public:

// TYPE MEMBERS //
    typedef binary_tree_node_iterator iterator;
    typedef binary_tree_node <Item>* node;

// MEMBER FUNCTIONS //
    binary_tree_node_iterator() : current(NULL), s(NULL), i(0) { }

    binary_tree_node_iterator(node initial) : current(initial), s(NULL), i(0)
    {
        start(current);
        restart();
    }
/*
    binary_tree_node_iterator(iterator &it)
    {
        if(this == &it)
            return *this;
        *this = it;
    }
*/
    ~binary_tree_node_iterator()
    {
        delete[] s;
    }
/*
    iterator operator=(const iterator it)
    {
        if(this == &it)
            return *this;

        current = it.current;
        s = it.s;
    }
*/
    Item& operator*() const
    { return current->data(); }

    iterator& operator++()// prefix increment
    {
        current = s[++i];
        return *this;
    }

    iterator operator++(int)// postfix increment
    {
        iterator original(current);
        original.current = current;
        current = s[++i];
        return original;
    }

    bool operator==(const iterator other) const
    { return current == other.current; }

    bool operator!=(const iterator other) const
    { return current != other.current; }

    void start(node root_ptr)
    {
        s = new node[tree_size(root_ptr)];
        inorder(root_ptr);
    }

//Restart iterator to point at the smallest element
    void restart()
    { i = 0; current = s[i];}

//Use inorder traversal to access each node
    void inorder(node root_ptr)
    {
        if(root_ptr){
            inorder(root_ptr->left());
            set_s(root_ptr);
            inorder(root_ptr->right());
        }
    }

//Assign node address to element in s
    node set_s(node leaf_ptr)
    {
        s[i++] = leaf_ptr;
        return leaf_ptr;
    }

private:

    node current;
    node *s; //points to dynamic array of pointers to binary_tree_node objects
    unsigned i; //subscript variable for s
};

#endif
