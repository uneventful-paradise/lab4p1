#include "Sort.h"
#include <random>
#include <cstdarg>
#include<cstring>
#include <string>
Sort::Sort(int nb_elem, int min_val, int max_val)
{
	srand(time(0));
	this->count = nb_elem;
	for (int i = 0; i < nb_elem; ++i)
		this->array[i] = rand() % (max_val - min_val) + min_val+1;//? de unde incepe si unde se termina intervalul
}

Sort::Sort(int a[], int size)
{	
	this->count = size;
	printf("%d \n", sizeof(a));
	for (int i = 0; i < this->count; ++i)
		this->array[i] = a[i];
}

Sort::Sort(char*string)
{
	int ind = 0;
	char* p = strtok((char*)string, ",");
	while (p!=NULL)
	{
		this->array[ind++] = std::stoi(p);
		//std::cout << p << " ";
		p = strtok(NULL, ",");
	}
	this->count = ind;
}

Sort::Sort(int num_args, ...)
{
	this->count = num_args;
	va_list list;
	va_start(list, num_args);
	for (int i = 0; i < num_args; ++i)
		this->array[i] = va_arg(list, int);
	va_end(list);

}

int Sort::GetElementsCount()
{
	return this->count;
}

int Sort::GetElementFromIndex(int index)
{
	return this->array[index];
}

void Sort::Print()
{
	for (int i = 0; i < this->count; ++i)
	{
		printf("%d ", this->array[i]);
	}
}