// DATE : 06/30/15
// FILE : Coin.cpp
// DESC : Class to hold each Coin object used in a Trial
//  1) Should capture the data members and member functions necessary to simulate flipping a coin
//  2) Assign a random probability between 0 and 1 to coin weight
//  3) Flip coin storing result of heads or tails

#ifndef COIN_H
#define COIN_H

// Library header files
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>

class Coin{

public :

// COPY CONTROL //
    Coin();
    Coin(double prob_arg) : prob(prob_arg) { }

// MEMBER FUNCTIONS //
    double gen_flip() { return flip = ((100 * prob) <= fdist(eng)); }
    double get_prob() { return prob; }

private :

// AUXILIARY FUNCTIONS //
    double gen_prob() { return pdist(eng); }

// DATA MEMBERS //
    double prob = 0; // probability of flipping tails
    static std::uniform_real_distribution<double> pdist; // used to generate probability
    static std::uniform_int_distribution<unsigned> fdist; // used to generated flip
    static std::default_random_engine eng;
    bool flip = false; // tails = true, heads = false
};

// static member definition
    std::uniform_real_distribution<double> Coin::pdist;
    std::uniform_int_distribution<unsigned> Coin::fdist(1, 100);
    std::default_random_engine Coin::eng;

#endif
