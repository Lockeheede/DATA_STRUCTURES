// Data_Structures.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Array Basics

#include <iostream>
#include <stdio.h>

using std::cout;
using std::endl;
using std::cin;

int main()
{

    //Array Basics:
    int A[5]; //Declare
    A[0] = 12;
    A[1] = 15;
    A[2] = 25;

    cout << sizeof(A) << endl; //int is 4 bytes * capacity of A [5] = 20
    cout << A[1] << endl; //Print the element of index 1
    printf("%d\n", A[2]);

    int B[5] = { 2,4,6,8,10 };//Initalize
    int C[] = { 2,4,6,8,10,12,14 };//size is based on the initalize amount
    int D[10] = { 2,4 }; //Accessing the rest of the elements = 0

    for (int i = 0; i < 10; i++)//Access elements in an array
    {
        cout << D[i] << endl;
    }

    for (int x : B)
        cout << x << endl;//foreach loop. X is now the index of whatever the array size is

    int n;
    cout << "Enter Size: ";
    cin >> n;
    //int E[n]; You cannot initalize the variable size. And some compilers do not compile them at all.
}

