//Project 2 : Part I
//09/05/14
//Set.cpp
//Class implementation for the Set class which models an unordered data structure

#include <iostream>
#include <algorithm>
#include <stdexcept>
#include "Set1.h"

using std::cout;
using std::cin;
using std::ostream;
using std::endl;

//Constructor creates a distinct copy of this Set object
Set::Set(const Set &obj)
{
//Memberwise copy
    set_vals = obj.set_vals;
    unset_vals = obj.unset_vals;

//Deep copy passed objects elements into this object
    std::copy(obj.data, (obj.data + set_vals), data);
}

//Inserts newItem into the set
void Set::insert(const value_type &newItem)
{
    try{
        if(isFull()){
            throw std::runtime_error("The set object must not be full to add new values.");
        }
//Add new element
        if(!contains(newItem)){
        data[set_vals] = newItem;
        ++set_vals;
        --unset_vals;
        }
    }
    catch(std::runtime_error err){
        cout << err.what();
    }
}

//If item is in the Set, it is removed
bool Set::remove(const value_type &item)
{
    if(contains(item)){
        int i = 0;

        for(; i < set_vals && data[i] != item; i++){
            ;//Null statement
        }
            for(; i < set_vals; i++){
                data[i] = data[i + 1];
            }
            set_vals--;
            unset_vals++;
            return true;
            }
    return false;
}

//Determines if a value is contained in the set
bool Set::contains(const value_type &item) const
{
    for(int i = 0; i < set_vals; i++){
        if(data[i] == item){
            return true;
        }
    }
    return false;
}

//Determines if one set is a subset of another
bool Set::subset(const Set &aSet) const
{
    size_type cnt(0);

    if(aSet.isEmpty()){
        return true;
    }

    for(int i = 0; i < aSet.set_vals; i++){
        if(contains(aSet.data[i])){
            ++cnt;
        }
    }
    return cnt == aSet.set_vals;
}

//Creates a Set that is a union of this Set and another
Set Set::aUnion(const Set &aSet) const
{
    Set s_small((set_vals < aSet.set_vals) ? *this : aSet);
    Set s_large((set_vals > aSet.set_vals) ? *this : aSet);
    Set s_union(s_large);

    size_type i = 0;
    while(s_union.set_vals <= CAPACITY && i != s_small.set_vals){
        for(; i < s_small.set_vals; i++){
            if(!(s_union.contains(s_small.data[i]))){
                s_union.insert(s_small.data[i]);
            }
        }
    }
    return s_union;
}

//Creates a set that is the intersection of this Set and another
Set Set::intersection(const Set &aSet) const
{
    Set s_intersect;
    Set s_small((set_vals < aSet.set_vals) ? *this : aSet);
    Set s_large((set_vals > aSet.set_vals) ? *this : aSet);

    for(int i = 0; i < s_small.set_vals; i++){
        if(s_large.contains(s_small.data[i])){
            s_intersect.insert(s_small.data[i]);
        }
    }
    return s_intersect;
}

//Determines if two sets are equal
bool Set::operator==(const Set &aSet) const
{
    if(set_vals != aSet.set_vals){
        return false;
    }

    return subset(aSet);
}

Set Set::operator=(Set obj)
{
    swap(*this, obj);
    return *this;
}

ostream& operator<<(ostream &out, const Set &obj)
{
    cout << "{ ";
    if(obj.set_vals != 0){
        for(int i = 0; i < obj.set_vals; i++){
            out << obj.data[i] << ", ";
        }
    }
    cout << "}" << endl;

    return out;
}

inline
void swap(Set &set1, Set &set2)
{
    using std::swap;
    swap(set1.set_vals, set2.set_vals);
    swap(set1.unset_vals, set2.unset_vals);
    swap(set1.data, set2.data);
}
