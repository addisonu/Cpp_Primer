// DATE : 07/01/15
// FILE : test.cpp
// DESC : Informal testing program

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

int main()
{
// Test Coin object
/*    for(std::size_t i = 0; i != 10; ++i){
        Coin coin0;
        Coin coin1(.5);
        Coin coin2;

        std::cout << std::boolalpha;
        std::cout << "coin0.prob = " << coin0.get_prob() << std::endl;
        std::cout << "coin1.prob = " << coin1.get_prob() << std::endl;
        std::cout << "coin2.prob = " << coin2.get_prob() << std::endl;
    }
*/

// Test Trial object
/*
    unsigned loop = 10;
    for(std::size_t j = 0; j != loop; ++j){
        //Trial trial0;
        Trial trial1(10);
        //Trial trial2(100, .5);

        std::cout << std::string(20, '=') + '\n' << "Run #" << j << std::endl;
        //std::cout << "trial0.tprob = " << trial0.run_trial() << std::endl;
        //std::cout << "prob = " << trial0.get_coin_prob() << std::endl;
        std::cout << "prob = " << trial1.get_coin_prob() << std::endl;
        double trial1_tprob = trial1.run_trial();
        std::cout << "trial1.tprob = " << trial1_tprob << std::endl;
        //std::cout << "trial2.tprob = " << trial2.run_trial() << std::endl;
        //std::cout << "prob = " << trial2.get_coin_prob() << std::endl;
    }
    Trial trial0, trial1(7, .77);
    std::cout << "before assignment\n" << std::endl;
    trial0.test();
    trial0 = trial1;
    std::cout << "after assignment\n" << std::endl;
    trial0.test();
*/

// Test experiment object
    for(std::size_t k = 0; k != 10; ++k){
        Experiment exp0, exp1(2, 11);
        std::cout << "exp0.get_real_prob() = " << exp0.get_real_prob() << std::endl;
/*
        std::cout << "exp1.get_real_prob() = " << exp1.get_real_prob() << std::endl;
        std::cout << "exp0 :\n";
        exp0.test();
        std::cout << '\n';
        std::cout << "exp1 :\n";
        exp1.test();
        std::cout << '\n';
        exp0.set_n(111);
        std::cout << "exp0.get_n() = " << exp0.get_n() << std::endl;
        exp0.set_m(222);
        std::cout << "exp0.get_m() = " << exp0.get_m() << std::endl;
        exp1 = exp0;

        std::cout << "exp1 :\n";
        exp1.test();
*/
        exp0.set_m(20);
        exp0.run_exp();
        std::cout << "exp0 :\n";
        exp0.test();
    }
    return 0;
}
