#include <iostream>
#include "Sort.h"

int main()
{
	int a[] = {1, 2, 3, 4, 5, 12, 15};//const int* a problema
	int count_a = sizeof(a) / sizeof(int);
	//const int* a = {1, 2, 3};
	const int* b = a;//de ce are sizeul 8
	//std::cout << sizeof(b);
	//Sort v1(7, 2, 10);//p1
	//Sort v1(a, sizeof(a)/sizeof(int));
	//Sort v1;//p2
	//Sort v1(a, count_a);
	//Sort v1(3, 1, 2, 3);
	char c[100] = { "10,40,100,5,70" };
	Sort v1(c);
	v1.Print();
}
