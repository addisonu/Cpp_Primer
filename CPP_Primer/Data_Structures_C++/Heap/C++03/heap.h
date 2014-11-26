//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: heap.h
//DESC: Definition of heap class

#ifndef HEAP_H
#define HEAP_H

#include <algorithm>
#include "pq_except.h"
#include "patient.h"

template<class T> class Heap;
template<class T> void swap(Heap<T> &heap1, Heap<T> &heap2);
template<class T> std::ostream& operator<<(std::ostream &out, const Heap<T> &obj);

template<class T> class Heap{
public:

    Heap(int max);          // parameterized class constructor
    ~Heap();            // class destructor

    Heap(const Heap<T> &obj);  // copy constructor for this class

    Heap<T>& operator=(Heap<T> obj); // assignment overload

    bool IsEmpty() const;
    // Function: Determines whether the heap is empty.
    // Post: Function value = (heap is empty)

    bool IsFull() const;
    // Function: Determines whether the heap is full.
    // Post: Function value = (heap is full)

    void add(T newItem);
    // Function: Adds newItem to this heap
    // Post: if (the heap is full) exception FullPQ is thrown;
    //       else newItem is in the heap.

    void remove(T &item);
    // Function: Removes the root from this heap
    // and returns it in item.
    // Post: If (the priority heap is empty) exception EmptyPQ is thrown;
    //       else highest priority element has been removed from heap.
    //       item is a copy of removed element.

    void sort(T vals[], size_t vsize, T new_val);
    // Function: Sorts objects of type T in descending order
    // Post: T objects are sorted from largest to smallest

private:
    int length;     //number of values in this heap
    T *items;      // dynamic array to store heap data
    int maxItems;  //capacity of this heap

// FRIENDS //
    friend void swap<T>(Heap<T> &heap1, Heap<T> &heap2);
    friend std::ostream& operator<<<T>(std::ostream &out, const Heap<T> &obj);
};

#include "heap.cpp" //Include heap implementation
#endif
