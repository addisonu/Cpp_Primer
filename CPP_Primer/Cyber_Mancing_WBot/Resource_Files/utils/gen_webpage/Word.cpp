// DATE : 03/18/15
// FILE : Word.cpp
// DESC : Implement Word class

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

#include "Word.h"

    std::ostream& operator<<(std::ostream& out, const Word obj)
    {
        std::cout << "word : " << obj.word << "\n"
            << "count : " << obj.count << "\n"
            << "URLs : " << "\n" << obj.url;

        return out;
    }
