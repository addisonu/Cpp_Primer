#include <iostream>
#include "IntCollection.h"

using namespace std;

int main()
{

    IntCollection c, d, e, f, h;
    
    for (int i = 0; i < 10; i++)
    {
      c.add(99);
    }    
    
    for (int i = 0; i < 3; i++)
    {
      d.add(i);
      e.add(i);
      f.add(i + 1);
    }

    cout << c.get(c.getSize() - 1) << '\n' << std::endl;

    cout << "Test overloaded insertion operator:" << std::endl;

    c << 77;
    cout << "c.data[end] = " << c.get(c.getSize() - 1) << '\n' << std::endl;

    cout << "Test overloaded equality operator:" << std::endl;

    cout << "Is d == e? " << (d == e);
    cout << std::endl;
    cout << "Is d == f? " << (d == f);
    cout << '\n' << std::endl;

    cout << "Test overloaded assignment operator:" << std::endl;

    h = f;
    cout << "Is f == h? " << (f == h);
    cout << std::endl;

    for(int n = 0; n < h.getSize(); n++){
	cout << "h[" << n << "] = " << h.get(n);
	cout << std::endl;
    }
  
    cout << std::endl;   

    cout << "Test copy constructor:" << std::endl; 

    IntCollection u = h;
    cout << "Is f == u? " << (f == u);
    cout << std::endl;

    for(int n = 0; n < u.getSize(); n++){
        cout << "u[" << n << "] = " << u.get(n);
        cout << std::endl;
    }
}
