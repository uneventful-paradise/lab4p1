#pragma once
#include<iostream>
class Sort {
    int array[100] = { 0 };
    int count = 0;
public:
    Sort(int nb_elem, int min_val, int max_val);
    Sort() : array{ 1, 2, 3, 4, 5 }, /*count(sizeof(array) / sizeof(int))*/ count(5) {}
    Sort(int a[], int count);
    Sort(int num_args, ...);
    Sort(char* mystring);
    void InsertSort(bool ascendent = false);
    void QuickSort(bool ascendent = false);
    void BubbleSort(bool ascendent = false);
    void Print();
    int  GetElementsCount();
    int  GetElementFromIndex(int index);
};
