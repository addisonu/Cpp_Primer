//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: const_bag6_iterator.h
//DSCR: Definition and implementation of const iterator for bag class

#ifndef CONST_BAG6_ITERATOR_H
#define CONST_BAG6_ITERATOR_H

#include <iterator>

class const_binary_tree_node_iterator : public std::iterator<std::forward_iterator_tag, const Item>{
public:

// TYPE MEMBERS //
    typedef const_binary_tree_node_iterator const_iterator;
    typedef  binary_tree_node <Item>* const_node;

// MEMBER FUNCTIONS //
    const_binary_tree_node_iterator() : current(NULL), s(NULL), i(0) { }

    const_binary_tree_node_iterator(const_node initial)
    {
        start(current);
        restart();
    }
/*
    const_binary_tree_node_iterator(const_iterator &it)
    {
        if(this == &it)
            return *this;
        *this = it;
    }
*/
    ~const_binary_tree_node_iterator()
    {
        delete[] s;
    }

/*
    const_iterator operator=(const_iterator it)
    {
        if(this == &it)
            return *this;

        current = it.current;
        s = it.s;
    }
*/

    const Item& operator*() const
    { return current->data(); }

    const_iterator& operator++()// prefix increment
    {
        current = s[++i];
        return *this;
    }

    const_iterator operator++(int)// postfix increment
    {
        const_iterator original(current);
        original.current = current;
        current = s[++i];
        return original;
    }

    bool operator==(const_iterator other) const
    { return current == other.current; }

    bool operator!=(const_iterator other) const
    { return current != other.current; }

    void start(const_node root_ptr)
    {
        s = new const_node[tree_size(root_ptr)];
        inorder(root_ptr);
    }

//Restart iterator to point at the smallest element
    void restart()
    { i = 0; current = s[i];}

//Use inorder traversal to access each node
    void inorder(const_node root_ptr)
    {
        if(root_ptr){
            inorder(root_ptr->left());
            set_s(root_ptr);
            inorder(root_ptr->right());
        }
    }

//Assign node address to element in s
    const_node set_s(const_node leaf_ptr)
    {
        s[i++] = leaf_ptr;
        return leaf_ptr;
    }

private:

    const_node current;
    const_node *s; //points to dynamic array of pointers to binary_tree_node objects
    unsigned i; //subscript variable for s
};

#endif
