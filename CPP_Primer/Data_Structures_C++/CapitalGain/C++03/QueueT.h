//10/16/14
//Project 4
//QueueT.h
//Class definition and implementation of template class to group transaction data with each stock

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <list>
#include <stdexcept>
#include "Transaction.h"

template <typename T> class Queue;
template <typename T> std::ostream& operator<<(std::ostream &out, const Queue<T> &obj);

template <typename T> class Queue {

public:
//TYPE MEMBERS//
    typedef typename std::list<T>::size_type size_type;

//CONSTUCTORS//
    Queue<T>(int cap = 10) : data(cap) { }

//GENERAL MEMBER FUNCTIONS//

//adds item to the end of queue
    void add(T item){data.push_back(item);}

//returns true if queue is empty
    bool isEmpty() const {return !data.size();};

//removes first item from queue
    T remove() {T ft = data.front(); data.pop_front(); return ft;}

//provide a copy of the object that is first in the queue
    T first() const
    {
        try{
            if(data.size() == 0)
                throw std::out_of_range("This Queue has no elements");
        }
        catch(std::out_of_range err){
            std::cerr << err.what();
        }
        return data.front();
    }

//updates the item in the front of the queue
    void updateFirst(T item) {*data.begin() = item;}

//returns iterator to the beginning of the list
    typename std::list<T>::iterator begin()
    {
        return data.begin();
    }

//returns size of data
    size_t size(){
        return data.size();
    }
private:

//DATA MEMBERS//
    std::list<T> data;

//FRIENDS//
friend std::ostream& operator<<<T>(std::ostream &out, const Queue<T>&);
};

template <typename T> std::ostream& operator<<(std::ostream &out, const Queue<T> &obj)
{
    for(typename std::list<T>::const_iterator i = obj.data.begin(); i != obj.data.end(); ++i){
        out << *i << std::endl;
    }
    return out;
}
#endif
