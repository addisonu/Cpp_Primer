

#ifndef INT_COLLECTION_H
#define INT_COLLECTION_H

class IntCollection
{
  private: 
    int size;
    int capacity;
    int *data;
    
    void doubleArraySize();
    
  public: 
    IntCollection();

//Declaration of copy constructor for IntCollection class
    IntCollection (const IntCollection &c);

    void add(int value);
    int get(int index);

    int getSize();

//Overloaded operator definitions
    IntCollection& operator= (const IntCollection &c);
    bool operator== (const IntCollection &c);
    IntCollection& operator<< (int value);

};

#endif
