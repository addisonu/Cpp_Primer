//ASSIGNMENT: Project 5
//DATE: 10/30/14
//FILE: bag6.cpp
//DSCR: Implementation of binary tree bag class

#include <cstdlib>
#include "bintree.h"

// NONMEMBER FUNCTIONS //

//Precondition: root_ptr is a root pointer of a non-empty binary search tree.
//Postcondition: The largest item in the binary search tree has been removed, and root_ptr now points to the root of the new (smaller) binary search tree. The reference parameter, removed, has been set to a copy of the removed item.

template <typename Item> void bst_remove_max(binary_tree_node <Item> *&root_ptr, Item &removed)
{
//If there is no right leaf, remove the root_ptr as the largest item and point it to the left leaf
    if(!root_ptr->right()){
        binary_tree_node <Item> *max_entry = root_ptr;
        removed = root_ptr->data();
        root_ptr = root_ptr->left();
        delete max_entry;
    }
//Make recursive call on right leaf which must hold largest item
    else{
        bst_remove_max(root_ptr->right(), removed);
    }
}

//Precondition: root_ptr is a root pointer of a binary search tree (or may be NULL for the empty tree)
//Postcondition: If target was in the tree, then one copy of target has been removed, root_ptr now points to the root of the new (smaller) binary search tree, and the function retruns true. Otherwise, if target was not in the tree, then the tree is unchanged, and the function returns false.

template <typename Item> bool bst_remove(binary_tree_node <Item> *&root_ptr, const Item &target)
{
//Base case bag is empty
    if(!root_ptr)
        return false;

//Make recursive call to search in left or right leaf
    else if(root_ptr->data() != target){
        if(target < root_ptr->data())
            return bst_remove(root_ptr->left(), target);
        else
            return bst_remove(root_ptr->right(), target);
    }
//Target has been found, remove and point root_ptr to right leaf or largest item on left leaf
    else{
        if(!root_ptr->left()){
            binary_tree_node <Item> *oldroot_ptr = root_ptr;
            root_ptr = root_ptr->right();
            delete oldroot_ptr;
        }
        else{
            bst_remove_max(root_ptr->left(), root_ptr->data());
        }
        return true;
    }
}

template <typename Item> bag<Item> operator+(const bag<Item> &b1, const bag<Item> &b2)
{
//Use compound assignment to add each argument to default initialized bag
    bag <Item> sum;
    sum += b1;
    sum += b2;

    return sum;
}

// MEMBER FUNCTIONS //
// CONSTRUCTORS AND DESTRUCTOR //
template <typename Item> bag<Item>::bag( ): root_ptr(NULL){}

template <typename Item> bag<Item>::bag(const bag& source)
{
//Make a copy of argument bag and pass address to root_ptr
    binary_tree_node <Item> *source_cpy = tree_copy(source.root_ptr);
    root_ptr = source_cpy;
}

template <typename Item> bag<Item>::~bag( )
{
//Call function to free bag memory and set root_ptr to nullptr
    tree_clear(root_ptr);
}

// MODIFICATION FUNCTIONS//
template <typename Item> typename bag<Item>::size_type bag<Item>::erase(const Item &target)
{
//Counter to hold number of elements in bag
    size_type cnt(0);

//Traverse bag and count number of elements
    while(erase_one(target)){
        ++cnt;
    }
    return cnt;
}

template <typename Item> bool bag<Item>::erase_one(const Item &target)
{
    return bst_remove(root_ptr, target);
}

template <typename Item> void bag<Item>::insert(const Item &entry)
{
//While loop control variable
    bool done(false);

//Make copy of this root_ptr
    binary_tree_node <Item> *cursor = root_ptr;

//Continue until correct position is found for entry
    while(!done){

//Add first element to bag
        if(size() == 0){
            root_ptr = new binary_tree_node <Item> (entry);
            done = true;
        }
//If left leaf is NULL place target in left leaf
        else if(entry <= cursor->data()){
            if(!cursor->left()){
                cursor->left() = new binary_tree_node <Item> (entry);
                done = true;
            }
//If left leaf not NULL point root_ptr to left leaf and continue position search
            else
                cursor = cursor->left();
        }
//If right leaf is NULL place target in right leaf
        else{
            if(!cursor->right()){
                cursor->right() = new binary_tree_node <Item> (entry);
                done = true;
            }
//If right leaf not NULL point root_ptr to right leaf and continue position search
            else
                cursor = cursor->right();
        }
    }
}

template <typename Item> void bag<Item>::operator+=(const bag &addend)
{
    binary_tree_node <Item> *addroot_ptr;

//Check for self assignment
    if(this == &addend){

//Make copy of bag to meet tree_copy preconditions, insert copy, delete copy
        addroot_ptr = tree_copy(addend.root_ptr);
        insert_all(addroot_ptr);
        tree_clear(addroot_ptr);
    }
//Insert bag argument
    else{
        insert_all(addend.root_ptr);
    }
}

template <typename Item> void bag<Item>::operator=(const bag &source)
{
//Check for self assignment
    if(this == &source)
        return;

//Free bag memory and point root_ptr to copy of bag argument
    tree_clear(root_ptr);
    root_ptr = tree_copy(source.root_ptr);
}

// CONSTANT functions
template <typename Item> typename bag<Item>::size_type bag<Item>::size( ) const
{
    return tree_size(root_ptr);
}

template <typename Item> typename bag<Item>::size_type bag<Item>::count(const Item &target) const
{
//Count of target
    unsigned many(0);

    binary_tree_node <Item> *cursor = root_ptr;

//Traverse bag size() times
    for(size_type i = 0; i != size(); i++){

//Return 0 if bag is empty
        if(cursor == NULL)
            return many;
//Search left leaf
        if(target < cursor->data())
            cursor = cursor->left();
//Search right leaf
        else if(target > cursor->data())
            cursor = cursor->right();
//Target is found, increment count
        else if(target == cursor->data()){
            many++;
            cursor = cursor->left();
        }
    }
    return many;
}

template <typename Item> std::ostream& operator<<(std::ostream &out, const bag<Item> &obj)
{
    print(obj.root_ptr, obj.size());
    return out;
}
