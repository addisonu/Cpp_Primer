

#include "IntCollection.h"
#include <iostream>

IntCollection::IntCollection()
{
  size = 0;
  capacity = 4;
  data = new int[4];
}

//Definition of copy constructor for IntCollection class
IntCollection::IntCollection( const IntCollection &c)
{
        size = c.size;
        capacity = c.capacity;

        if(c.data){
                data = new int[capacity];
                for(int n = 0; n < size; n++){
                data[n] = c.data[n];
                }

        }
        else{
                data = 0;
        }
}

//Overloaded assignment operator definition
IntCollection& IntCollection::operator= (const IntCollection &c)
{
        if(this == &c){
                return *this;
        }

        delete[] data;

        size = c.size;
        capacity = c.capacity;

        if(c.data){
                data = new int[capacity];
                for(int n = 0; n < size; n++){
                        data[n] = c.data[n];
                }

        }
        else{
                data = 0;
        }
        return *this;
}

void IntCollection::add(int value)
{
    // Check to see if we need more space
    if (size == capacity)
    {
      doubleArraySize();
    }
    
    // Add the new value
    data[size] = value;
    size++;
}

int IntCollection::get(int index)
{
    return data[index];
}

int IntCollection::getSize()
{
    return size;
}

//Overloaded equality operator definition
bool IntCollection::operator== (const IntCollection &c)
{
        int count(0);
        if(size == c.size){
                for(int n = 0; n < size; n++){
                        if(data[n] == c.data[n]){
                                count++;
                        }
                }
                if(count != size){
                        count = 0;
                }
        }
        return count;
}

//Overloaded output operator definition                      
IntCollection&  IntCollection::operator<< (int value)        
{                                                            
        add(value);                                          
        return *this;   
}

/*************************
 * Helpers		 *
 *************************/

void IntCollection::doubleArraySize()
{
  // Allocate a new array, twice as big
  int *newArray = new int[capacity * 2];
  
  // Copy values from data to new array
  for (int i = 0; i < size; i++)
  {
      newArray[i] = data[i];
  }
  
  // delete the old array? 
  
  // point data at the new array
  data = newArray;

  // double capacity value
  capacity *= 2;
  
  // Debugging output
  std::cout << "(capacity doubled: " << capacity << ")\n";
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    


