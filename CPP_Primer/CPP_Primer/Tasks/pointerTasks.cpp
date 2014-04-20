//Practice with pointers

#include <iostream>

void noNegatives(int *x);
void swap(int *p1, int *p2);

int main()
{
	int x(0), y(0);
	int *p1 = &x;
	
	*p1 = 99;
	
	std::cout << x << std::endl;
	std::cout << *p1 << std::endl;

	p1 = &y;	
	*p1 = -300;

	int temp(0), *p2;

	temp = x;
	p2 = &x;
	*p2 = *p1;	
	*p1 = temp;

	noNegatives(&x);
	noNegatives(&y);	

	p2 = &x;
	std::cout << *p2 << std::endl;
	p2 = &y;
	std::cout << *p2 << std::endl;

	int a[2];
	
	p2 = &x;
	a[0] = *p2;
	p2 = &y;
	a[1] = *p2;

	std::cout << &a[0] << std::endl;
	std::cout << &a[1] << std::endl;

	p1 = &a[0];
	p2 = &a[1];
	temp = *p1;
	*p1 = *p2;
	*p2 = temp;

	std::cout << *p1 << std::endl;
	std::cout << *p2 << std::endl;
	
	swap(&x, &y);
	
	std::cout << x << std::endl;
	std::cout << y << std::endl;
	
	swap(&a[0], &a[1]);

	std::cout << a[0] << std::endl;
	std::cout << a[1] << std::endl;

	return 0;
}

void noNegatives(int *x)
{
	if(*x < 0){
		*x = 0;
	}
}

void swap(int *p1, int *p2)
{
	int temp(*p1);
	
	*p1 = *p2;
	*p2 = temp;
}
