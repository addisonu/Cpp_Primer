// DATE : 05/28/15
// FILE : APAN:05.28.15.cpp
// DESC : function and class friendship

#include <iostream>

class NClass;
template <typename T> class BClass;
template <typename T> class DClass;
template <typename T> T& idB(BClass<T> &obj);
template <typename T> T& idD(DClass<T> &obj);
template <typename T> std::ostream& print_all(std::ostream& out, NClass objn, BClass<T> &objb, DClass<T> &objd);

// Class without inheritance
class NClass{

public :

// MEMBER FUNCTIONS //
    NClass() { }
    NClass(int val) { n = val; }
    int get_n() { return n; }
    template <typename T> void set_t(BClass<T> &obj, T val) { obj.t = val; }
    template <typename T> void set_t(DClass<T> &obj, T val) { obj.dt = val; }
    void set_n(int val) { n = val; }

private :

// DATA MEMBERS //
    int n = 7;

// FRIENDS //
    template <typename T> friend std::ostream& print_all(std::ostream& out, NClass objn, BClass<T> &objb, DClass<T> &objd);
};

// Base class
template <typename T> class BClass{

public :

// MEMBER FUNCTIONS //
    BClass() { }
    BClass(T val) { t = val; }
    T get_t() { return t; }
    void set_t(T val) { t = val; }

private :

// DATA MEMBERS //
    T t;

// FRIENDS //
// Member function of NClass is friend of BClass
    friend T& idB<T>(BClass<T> &obj);
    friend std::ostream& print_all<T>(std::ostream& out, NClass objn, BClass<T> &objb, DClass<T> &objd);

};

// Derived class
template <typename T> class DClass : public BClass<T>{

public :

// MEMBER FUNCTIONS //
    DClass<T>() { }
    DClass<T>(T val1, T val2) : BClass<T>(val1), dt(val2) { }
    T get_dt() { return dt; }
    void set_dt(T val) { dt = val; }

private :

// DATA MEMBERS //
    T dt;

// FRIENDS //
// NClass is friend of DClass
    friend class NClass;
    friend T& idD<T>(DClass<T> &obj);
    friend std::ostream& print_all<T>(std::ostream& out, NClass objn, BClass<T> &objb, DClass<T> &objd);
};

// friend functions
template <typename T> std::ostream& print_all(std::ostream& out, NClass objn, BClass<T> &objb, DClass<T> &objd)
{
    out << "n : " << objn.n << std::endl
        << "objb.t : " << objb.t << std::endl
        << "objd.t : " << objd.t << std::endl
        << "dt : " << objd.dt << std::endl;
    return out;
}

template <typename T> T& idB(BClass<T> &obj) { return obj.t; }
template <typename T> T& idD(DClass<T> &obj) { return obj.dt; }

int main()
{
// var for print function
    NClass objn;
    BClass<char> objb('u');;
    DClass<char> objd('n', 'a');

// print all data members of classes NClass, BClass, and DClass
    print_all<char>(std::cout, objn, objb, objd);

// return t data member of class BClass and dt of DClass
    std::cout << "idB<char>(objb) : " << idB<char>(objb) << std::endl;
    std::cout << "idD<char>(objd) : " << idD<char>(objd) << std::endl;

    return 0;
}
