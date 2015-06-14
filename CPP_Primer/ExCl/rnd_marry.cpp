// DATE : 06/14/15
// FILE : rnd_marry
// DESC : Write a program to discover the answer to this puzzle: "Let's say men and women are paid equally (from the same uniform distribution). If women date randomly and marry the first man with a higher salary, what fraction of the population will get married

#include <iostream>
#include <string>
#include <random>
#include <vector>

class Marry_higher_salary{

public :

// CONTRUCTORS //
    Marry_higher_salary() = default; // default
    Marry_higher_salary(const unsigned long sample) { sample_sz = sample;  } // Takes sample size

// MEMBER FUNCTIONS //
    void reset() { married_cnt = 0; }
    void new_woman() { woman = dist(eng); } // Generate woman with salary

    void marry() { ++married_cnt; } // woman marries man with higher salary

    void date() // Generate man with salary
    {
        for(std::size_t i = 0; i != num_dates; ++i){
            if(woman < dist(eng)){
                marry();
                break;
            }
        }
    }

    double married_pcnt() { return static_cast<double>(married_cnt) / pop_sz; } // return percentage of pop that marries, assume equal number of men and women

        double run_exp()
    {
        reset();
        for(std::size_t i = 0; i != sample_sz; ++i){
            new_woman();
            date();
        }
        return married_pcnt();
    }
private :

// DATA MEMBERS //

    static std::default_random_engine eng; // random number engine
    static std::uniform_int_distribution<unsigned> dist; // random number uniform distribution
    static unsigned married_cnt; // number of women who marry
    static unsigned num_dates; // number of men each woman will date
    static unsigned long pop_sz; // hold entire population == 2*women_sample_size
    static unsigned long sample_sz; // number of woman in experiment
    double woman = 0; // current dating woman w/ salary
};

// Definitions of static members
    std::default_random_engine Marry_higher_salary::eng;
    std::uniform_int_distribution<unsigned> Marry_higher_salary::dist(1, 100);
    unsigned Marry_higher_salary::married_cnt = 0;
    unsigned Marry_higher_salary::num_dates = 100;
    unsigned long Marry_higher_salary::pop_sz = 2 * sample_sz;
    unsigned long Marry_higher_salary::sample_sz = 100;

int main()
{
    // Run different experiments by changing value for data member num_dates and number of times experiment is run
    Marry_higher_salary married_pop_pcnt;
    for(std::size_t i = 0; i != 50; ++i){
        std::cout << married_pop_pcnt.run_exp() << std::endl;
    }
    return 0;
}
