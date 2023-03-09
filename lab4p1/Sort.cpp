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
//	printf("%d \n", sizeof(a));
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

void Sort::BubbleSort(bool ascend)
{
	for(int i = 0; i < this->count-1; ++i)
		for(int j = i+1; j < this->count; ++j)
			if ((ascend and this->array[i] > this->array[j]) or (!ascend and this->array[i] < this->array[j]))
			{
				int aux = this->array[i];
				this->array[i] = this->array[j];
				this->array[j] = aux;
			}
}
void Sort::InsertSort(bool ascend)
{
	for (int i = 1; i < this->count; ++i)
	{
		int temp = this->array[i];
		int j = i - 1;
		while (j >= 0 and ((ascend and this->array[j] > temp) or (!ascend and this->array[j] < temp)))
		{
			this->array[j + 1] = this->array[j];
			j--;
		}
		if (this->array[j] != temp) //???ce-i cu warningul asta
			this->array[j + 1] = temp;
	}
}

void partition(int a[], int p, int q, int&k, bool ascend)
{
	int x = a[p];
	//std::cout << "pivotul este " << x << " ";
	int i = p + 1;
	int j = q;
	while (i <= j)
	{
		if ((a[i] <= x and ascend) or (a[i] >= x and !ascend))
			i++;
		if ((a[j] >= x and ascend) or (a[j] <= x and !ascend))
			j--;
		if ((i < j) and ((ascend and a[i] > x and a[j] < x) or (!ascend and a[i] < x and a[j] > x)))
		{
			int aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	}
	k = i-1;
	a[p] = a[k];
	a[k] = x;
	//std::cout << "pivotul este " << a[k] << " ";
}

void quickSort(int a[], int p, int q, bool ascend)
{
	int k = 0;
	if (p < q)
	{
		partition(a, p, q, k, ascend);
		quickSort(a, p, k - 1, ascend);
		quickSort(a, k + 1, q, ascend);
	}
}

void Sort::QuickSort(bool ascend)
{
	quickSort(this->array, 0, this->count - 1, ascend);
}