// DATE : 06/30/15
// FILE : Experiment.h
// DESC : Class to hold each experiment object of coin_toss program
//  1) Should capture the data members and member functions necessary for a single experiment
//  2) Experiment consists of m trials
//  3) Create table of probabilities for each experiment

#ifndef EXPERIMENT_H
#define EXPERIMENT_H

// Library header files
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <utility>

// Class header files
#include "Trial.h"
#include "Coin.h"

class Experiment{

public :

// COPY CONTROL //
    Experiment() { }
    Experiment(unsigned m_arg, unsigned n_arg) : m(m_arg), n(n_arg) { }

// MEMBER FUNCTIONS //
    unsigned get_m() { return m; }
    void set_m(unsigned m_arg) { m = m_arg; }
    unsigned get_n() { return n; }
    void set_n(unsigned n_arg) { n = n_arg; }
    void run_exp()
    {
        for(unsigned i = 0; i != m; ++i){
            Trial tmp_trial(n, coin);
            trial = tmp_trial;
            ptable.push_back(trial.run_trial());
        }
    }

    double get_real_prob() { return trial.get_coin_prob(); }

    std::vector<double>& get_table() { return ptable; }

    Experiment& operator=(const Experiment &rhs)
    {
        trial = rhs.trial;
        ptable = rhs.ptable;
        m = rhs.m;
        n = rhs.n;
        return *this;
    }

    void test()
    {
        std::cout << "m = " << m << std::endl;
        std::cout << "n = " << n << std::endl;
        std::cout << "ptable : \n";
        for(auto ele : ptable)
            std::cout << ele << ", ";
        std::cout << std::endl;
    }

private :

// AUXILIARY FUNCTIONS //
// DATA MEMBERS //
    Trial trial;
    Coin coin;
    std::vector<double> ptable; // holds the m probabilities for each n
    unsigned m = 10;
    unsigned n = 10;
};

#endif

