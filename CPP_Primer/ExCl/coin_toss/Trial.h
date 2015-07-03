// DATE : 06/30/15
// FILE : Trail.cpp
// DESC : Class to hold each Trial object of an experiment
//  1) Should capture the data members and member functions necessary for a single trial run
//  2) Trial consists of n flips of a coin
//  3) Return probability of flipping head or tails for each trial

#ifndef TRIAL_H
#define TRIAL_H

// Library header files
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

// Class header files
#include "Coin.h"

class Trial{

public :

// COPY CONTROL //
    Trial() { }
    Trial(unsigned n_arg) : n(n_arg) { }
    Trial(unsigned n_arg, Coin coin_arg) : n(n_arg) { coin = coin_arg; }

// MEMBER FUNCTIONS //
    double run_trial()
    {
        for(unsigned i = 0; i != n; ++i){
            if(coin.gen_flip())
                ++freq;
        }
        return tprob = static_cast<double>(freq) / n;
    }

    Trial& operator=(const Trial &rhs)
    {
        n = rhs.n;
        tprob = rhs.tprob;
        freq = rhs.freq;
        coin = rhs.coin;
        return *this;
    }

    double get_coin_prob() { return coin.get_prob(); }

    void test()
    {
        std::cout << "n = " << n << std::endl;
        std::cout << "tprob = " << tprob << std::endl;
        std::cout << "freq = " << freq << std::endl;
        std::cout << "prob = " << get_coin_prob() << std::endl;
    }

private :

// AUXILIARY FUNCTIONS //
// DATA MEMBERS //
    unsigned n = 10; // number of trials
    double tprob = 0; // probability of flipping head or tails as concluded from trial
    unsigned freq = 0;
    Coin coin;
};

#endif
