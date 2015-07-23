// DATE : 07/22/15
// FILE : APAN:07.22.15.cpp
// DESC : Prevent objects of class type from being copied and/or created by defining copy control members as deleted

#include <iostream>
#include <string>

// Class that defines copy constructor and copy-assignment operator as deleted
class DCon{
    DCon() { }
    DCon(const DCon &obj) = delete;
    DCon& operator=(const DCon &obj) = delete;
};

// Class that defines its destructor as deleted
class DDes{
    ~DDes() = delete;
};

// Class for which compiler defines synthesized default constructor and destructor as deleted
class DSynDefDes{
    DCon obj;
};

// Class for which compiler defines synthesized copy constructor and copy-assignment operator as deleted
class DSynCopAsg{
    DDes obj;
};

int main()
{
    return 0;
}
