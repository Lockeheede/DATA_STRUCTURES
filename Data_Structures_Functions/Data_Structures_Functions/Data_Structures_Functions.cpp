// Data_Structures_Functions.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Functions. Should I do assignments in functions from now on or keep them seperate? 
// I think for learning purposes, keeping them seperate is good. But I can also put them togther
// I should do both to practice twice in both learning a specific topic and learning how to procedurally program

#include <iostream>

using namespace std;

//Prototype the function first
int add(int a, int b)//Declare a function. It is using formal parameters
{
    int c;
    c = a + b;
    return c; //This is sent back to the function calling this function! 
}

int main()
{
    int a = 10; int b = 10;
    int z;
    z = add(a, b);//Actual parameters (or arguments??)
    cout << z << endl;
}


