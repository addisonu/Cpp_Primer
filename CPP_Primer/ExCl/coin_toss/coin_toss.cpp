// DATE : 06/30/15
// FILE : coin_toss.cpp
// DESC : Program to find unknown probability with flipping heads or tails
// Tentative approach:
//  1) Given a coin with an unknown probability of flipping heads or tails, how many times must you flip the coin to discover that probability
//  2) Flip the coint n times, the result is p_tails = k, p_heads = 1 - k
//  3) Repeat this experiment m times
//  4) Make a table, i.e distribution for the probability of each probability
//  5) Continue steps 1 - 4 increasing n for each experiment, until some level of certainty is reached, by taking the limit of the elements in the distribution

// Library header files
#include <iostream>
#include <random>
#include <vector>
#include <string>
#include <utility>

// Class header files
#include "Experiment.h"
#include "Trial.h"
#include "Coin.h"

bool limit(std::vector<double> table, double epsilon);

int main()
{
    Experiment experiment;
    unsigned runs(0);
    unsigned trials(0);
    double epsilon(0);

    // Run experiment until the limit which is the probability is found
    do{
        std::cout << "How many times will you run the experiment?\n";
        std::cin >> runs;
        std::cout << "How many trials will you run for each experiments?\n";
        std::cin >> trials;
        Experiment tmp_exp(runs, trials);
        experiment = tmp_exp;
        experiment.run_exp();
    }while(!limit(experiment.get_table(), epsilon));

    std::cout << std::boolalpha;
    std::cout << "Was the probability found? " << (epsilon > (experiment.get_table().back() - experiment.get_real_prob())) << std::endl;
    return 0;
}

bool limit(std::vector<double> table, double epsilon)
{
    unsigned prob_diff(0); // holds the greatest difference between any two probabilites in probability table
    unsigned tmp_diff(0);
    for(unsigned i = 0; i != table.size() - 1; ++i){

        if(prob_diff < (tmp_diff = std::abs(table[i] - table[i + 1])))
            prob_diff = tmp_diff;
    }
    return epsilon >= prob_diff;
}

