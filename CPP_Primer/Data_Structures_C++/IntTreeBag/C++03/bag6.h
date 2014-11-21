//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: bag6.h
//DSCR: Definition of binary tree bag class

// FILE: bag6.h (part of the namespace main_savitch_10)
// TEMPLATE CLASS PROVIDED: bag<Item>
//     (a container template class for a collection of items)
//
// TYPEDEFS for the bag<Item> class:
//   bag<Item>::value_type
//     bag<Item>::value_type is the data type of the items in the bag. It may
//     be any of the C++ built-in types (int, char, etc.), or a class with a
//     default constructor, a copy constructor, an assignment operator, and a
//     less-than operator forming a strict weak ordering.
//
//   bag<Item>::size_type
//     bag<Item>::size_type is the data type of any variable that keeps track
//     of how many items are in a bag.
//
// CONSTRUCTOR for the bag<Item> class:
//   bag( )
//     Postcondition: The bag is empty.
//
// MODIFICATION MEMBER FUNCTIONS for the bag<Item> class:
//   size_type erase(const Item& target)
//     Postcondition: All copies of target have been removed from the bag. The
//     return value is the number of copies removed (which could be zero).
//
//   bool erase_one(const Item& target)
//     Postcondition: If target was in the bag, then one copy of target has been
//     removed from the bag; otherwise the bag is unchanged. A true return value
//     indicates that one copy was removed; false indicates that nothing was
//     removed.
//
//   void insert(const Item& entry)
//     Postcondition: A new copy of entry has been inserted into the bag.
//
//   void operator +=(const bag& addend)
//     Postcondition: Each item in addend has been added to this bag.
//   void insert_all(const binary_tree_node <Item> *addroot_ptr    )
//   Precondition: addroot_ptr is the root pointer of a binary search tree that is separate from the binary search tree of the bag that activated this method.
//   Postcondition: All the items from the addroot_ptr's binary search tree have been added to the binary search tree of the bag that activated this method.
//
// CONSTANT MEMBER FUNCTIONS for the bag<Item> class:
//   size_type size( ) const
//     Postcondition: Return value is the total number of items in the bag.
//
//   size_type count(const Item& target) const
//     Postcondition: Return value is number of times target is in the bag.
//
// NONMEMBER FUNCTIONS for the bag class:
//   bag operator +(const bag& b1, const bag& b2)
//     Postcondition: The bag returned is the union of b1 and b2.
//
// VALUE SEMANTICS for the bag class:
//   Assignments and the copy constructor may be used with bag objects.
//
// DYNAMIC MEMORY USAGE by the bag: 
//   If there is insufficient dynamic memory, then the following functions
//   throw bad_alloc: The constructors, insert, operator +=, operator +, and
//   the assignment operator.

#ifndef BAG6_H
#define BAG6_H

#include <cstdlib>     // Provides NULL and size_t
#include <iterator>     //Used by iterator companion types
#include "bintree.h"   // Provides binary_tree_node and related functions

namespace main_savitch_10
{
//Forward declarations for friend functions
template <typename Item> class bag;
template <typename Item> std::ostream& operator<<(std::ostream &out, const bag <Item> &obj);

    template <typename Item>
    class bag
    {
public:

// NESTED CLASSES //
    #include "bag6_iterator.h"
    #include "const_bag6_iterator.h"

// TYPE MEMBERS //
    typedef std::size_t size_type;
    typedef Item value_type;
    typedef binary_tree_node_iterator iterator;
    typedef const_binary_tree_node_iterator const_iterator;

// MEMBER FUNCTIONS //

// CONSTRUCTORS and DESTRUCTOR //
    bag( );//combine default constructor with copy constructor
    bag(const bag& source);
    ~bag( );

// MODIFICATION FUNCTIONS //
    size_type erase(const Item& target);
    bool erase_one(const Item& target);
    void insert(const Item& entry);
    void operator+=(const bag& addend);
    void operator=(const bag& source);

// CONSTANT FUNCTIONS //
    size_type size( ) const;
    size_type count(const Item& target) const;

// ITERATOR FUNCTIONS //
    iterator begin() { return iterator(root_ptr); }
    const_iterator cbegin() const { return const_iterator(root_ptr); }
    iterator end() { return iterator(); }//uses default constructor
    const_iterator cend() const { return const_iterator(); }//uses default constructor

private:

    binary_tree_node<Item> *root_ptr; // Root pointer of binary search tree

// PRIVATE MEMBER FUNCTION DEFINITIONS //
    void insert_all(const binary_tree_node <Item> *addroot_ptr)
    {
        if(addroot_ptr){
            insert(addroot_ptr->data());
            insert_all(addroot_ptr->left());
            insert_all(addroot_ptr->right());
        }
    }
// FRIENDS //
    friend std::ostream& operator<<<Item>(std::ostream &out, const bag<Item> &obj);
};

// NONMEMBER FUNCTIONS //
    template <typename Item> bag<Item> operator+(const bag<Item> &b1, const bag<Item>& b2);
    template <typename Item> std::ostream& operator<<(std::ostream &out, const bag<Item> &obj);

#include "bag6.cpp" // Include the implementation.
}
#endif
