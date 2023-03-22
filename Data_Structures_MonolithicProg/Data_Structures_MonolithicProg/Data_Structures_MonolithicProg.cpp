// Data_Structures_MonolithicProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Monolithic Program

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int length = 0, width = 0;//Good practice to initialize of 0 

    printf("Enter Length and Breath: ");
    cin >> length >> width;

    int area = length * width;
    int perimeter = 2 * (length + width);

    printf("Area: %d\nPerimeter: %d\n", area, perimeter);
}

