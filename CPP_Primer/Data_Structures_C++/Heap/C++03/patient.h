//DATE: 11/23/14
//ASSIGNMENT: Project 6
//FILE: patient.h
//DESC: Definition and implementation of patient class, a type to hold all related patient information

#ifndef PATIENT_H
#define PATIENT_H

#include <iostream>
#include <string>

class Patient{

public:
// CONSTRUCTOR //
    Patient(std::string pname = "N/A", std::string pmalady = "N/A", int ppriority = 0) : name(pname), malady(pmalady), priority(ppriority){ }

// MEMBER FUNCTIONS //
    std::string get_name(){ return name; }
    std::string get_malady(){ return malady; }
    int get_priority(){ return priority; }

// OVERLOADED OPERATOR MEMBERS //
// Allow ordering of patient objects based on priority field
    bool operator==(const Patient &rhs)
    { return priority == rhs.priority; }
    bool operator<(const Patient &rhs)
    { return priority < rhs.priority; }
    bool operator>(const Patient &rhs)
    { return priority > rhs.priority; }

private:
    std::string name;
    std::string malady;
    int priority;

// FRIENDS //
    friend std::ostream& operator<<(std::ostream &out, const Patient obj);
};

    std::ostream& operator<<(std::ostream &out, const Patient obj)
    {
        out << obj.name << " " << obj.malady << " " << obj.priority;
        return out;
    }
#endif
