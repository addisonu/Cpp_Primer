//DATE : 03/17/15
//FILE : Indexer.cpp
//DESC : Implementation of Indexer class
//VERSION : 0

/*BUGS :
 */

#include "Indexer.h"
#include "Word.h"
#include "cpp_webpage.h"

// FRIENDS //
std::ostream& operator<<(std::ostream &out, const Indexer obj)
{
// If there are any Word object to print
    if(obj.index.size() != 0){

// Iterate through index and print each Word
        for(auto ele : obj.index){
            out << ele << std::endl;
        }
    }
    return out;
}

