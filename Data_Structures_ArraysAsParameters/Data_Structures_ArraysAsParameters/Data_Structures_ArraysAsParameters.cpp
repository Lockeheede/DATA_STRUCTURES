// Data_Structures_ArraysAsParameters.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Arrays as parameters

#include <iostream>

using namespace std;

void fun0(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[i] = i + 5;
}

int * fun(int n)
{
    int *p;
    p = new int[n];//Instead of malloc. 
    for (int i = 0; i < n; i++)
        p[i] = i + 1;//This dynamic allocation in the function can help you create an array outside of main.
    return p;
}

int main()
{
    int B[] = { 2,4,6,8,10 };
    fun0(B, 5);//This function should have changed the values of B, because arrays pass as address.
    for (int x : B)
        cout << x << " ";//You can't use foreach in pointers, but arrays are fine
    int *A;
    int sz = 5;//Changing sz will change the elements of the function fun's A up to the number you change sz to. 
    A = fun(sz);
    for (int i = 0; i < sz; i++)
        cout << A[i] << " ";
}

