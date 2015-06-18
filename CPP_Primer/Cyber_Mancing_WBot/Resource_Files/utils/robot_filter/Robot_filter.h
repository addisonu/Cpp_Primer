// DATE : 06/15/15
// FILE : Robot_filter2.h
// DESC : Class to create object that will search robots.txt file for a given URL

// LEFT OFF //
/*
 */

// BUGS //
/*
 */

// POSSIBLE SOLUTIONS/ADDITIONS //
/*
 */

// NOTES //
/*
 */

#include <iostream>
#include <fstream>

#ifndef ROBOT_FILTER_H
#define ROBOT_FILTER_H

class Robot_filter{

public :

// TYPE MEMBERS //
    const long ARR_SIZE = 50;

// CONSTRUCTORS //
    Robot_filter() = default;
    Robot_filter(const char *file_arg, const char *url_arg) : file(file_arg), file_sz(strlen(file_arg)),url(url_arg), url_sz(strlen(url))
    {
        cstr = new char[ARR_SIZE];
        cstr_sz = 0;
        cstr_cap = ARR_SIZE;
        exclusions = new char*[ARR_SIZE];
        exclusions_sz = 0;
        exclusions_cap = ARR_SIZE;
    }

// MEMBER FUNCTIONS //
    bool LoadExclusionFile(std::fstream &file);

    bool IsUrlPathExcluded();

    void set_url(const char *url_arg) { url = url_arg; }

    void set_file(const char *file_arg) { file  = file_arg; }

    void clear_cstr()
    {
        char * tmp = new char[ARR_SIZE];
        std::swap(cstr, tmp);
        cstr_sz = 0;
        delete[] tmp;
    }

    void add_cstr(char ch)
    {
        if(cstr_cap > cstr_sz){
            cstr[cstr_sz] = ch;
            cstr[cstr_sz + 1] = '\0';
        }
        else{
            char *tmp = new char[cstr_cap * 2];
            strcpy(tmp, cstr);
            tmp[cstr_sz] = ch;
            std::swap(cstr,tmp);
            cstr_cap *= 2;
            delete [] tmp;
        }
            ++cstr_sz;
    }

    void add_exclusions(char *exclusion)
    {
        char *tmp_cstr = new char[strlen(exclusion)];
        strcpy(tmp_cstr, exclusion);
        if(exclusions_cap > exclusions_sz)
            exclusions[exclusions_sz] = tmp_cstr;
        else{
            char **tmp = new char*[exclusions_cap * 2];
            for(std::size_t i = 0; i != exclusions_sz; ++i){
                tmp[i] = exclusions[i];
            }
            tmp[exclusions_sz] = exclusion;
            std::swap(exclusions, tmp);
            exclusions_cap *= 2;
            delete[] tmp;
        }
        ++exclusions_sz;
    }

private :

// DATA MEMBERS //
    const char *file = nullptr;
    std::size_t file_sz = 0;
    const char *url = nullptr;
    std::size_t url_sz = 0;
    char *cstr = nullptr;
    std::size_t cstr_sz = 0;
    std::size_t cstr_cap = 0;
    char **exclusions = nullptr;
    std::size_t exclusions_sz = 0;
    std::size_t exclusions_cap = 0;
};
#endif
