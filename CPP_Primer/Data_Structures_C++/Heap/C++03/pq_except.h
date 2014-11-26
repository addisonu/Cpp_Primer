//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: pq_except.h
//DESC: Exception objects thrown for attempted operations on full heap

#ifndef PQ_EXCEPTION_H
#define PQ_EXCEPTION_H

#include <stdexcept>

class fullpq: public std::out_of_range{
public:
    explicit fullpq(const std::string &msg) : std::out_of_range(msg){ }
};

class emptypq: public std::out_of_range{
public:
    explicit emptypq(const std::string &msg) : std::out_of_range(msg){ }
};
#endif
