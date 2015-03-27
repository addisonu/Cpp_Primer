//DATE : 03/17/15
//FILE : Indexer.cpp
//DESC : Implementation of Indexer class
//VERSION : 0

/*BUGS :
 */

#include "Indexer1.h"
#include "Word.h"
#include "cpp_webpage.h"

// FRIENDS //
std::ostream& operator<<(std::ostream &out, const Indexer obj)
{
    if(obj.index.size() != 0){
        for(auto ele : obj.index){
            out << ele << std::endl;
        }
    }
    return out;
}

