//implement myQueue template class using STL stack

#ifndef MY_QUEUE
#define MY_QUEUE

#include <stack>
#include <deque>

template <typename T> class myQueue{

public :

// type members
    typedef typename std::stack<T>::size_type size_type;

// constructors
    myQueue<T>() { }

// other member functions
    void push(T val)
    {
        input.push(val);
    }

// preconditions : not both input and output are empty
    void pop()
    {
// if output has elements
        if(!output.empty())
            output.pop();

// if output has no elements
        else{
            reload();
            output.pop();
        }
    }

// Preconditions : not both of output and input are empty
    T front()
    {
        if(!output.empty()){
            return output.top();
        }
        else{
            reload();
            return output.top();
        }
    }

// Preconditions : not both of output and input are empty
    T back()
    {
        if(input.empty())
            return last;
        else
            return input.top();
    }

    size_type size()
    { return input.size() + output.size(); }

    bool empty() const
    { return input.empty() && output.empty(); }

    void swap(myQueue &rhs)
    {
        input.swap(rhs.input);
        output.swap(rhs.output);
    }

private :
// data members
    std::stack<T> output;
    std::stack<T> input;
    T last;

// helper functions

// reload ouput
// preconditions : input is not empty and output is empty
    void reload()
    {
        size_type cnt = input.size();
        last = input.top();
        for(size_type i = 0; i != cnt; ++i){
            output.push(input.top());
            input.pop();
        }
    }
};
#endif
