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

//Pass by Address. Also a swap function.
void swap(int *a, int *b)//Notice pointers in declaration
{
    int temp;
    temp = *a;//De-referencing a pointer to have to access what it is pointing to
    *a = *b;//Since the pointers from the formal parameters are pointing to the actual parameters
    *b = temp;//Changing the value of dereferenced variables changes the actual as well. 
}

//Pass by Reference
void swapRef(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
    //Seems easier, but only best suited for small functions. 
    //Complex functions that use loops, etc might cause issues
}

int main()
{
    //Regular Function. Pass by Value
    int a = 10; int b = 10;
    int z;
    z = add(a, b);//Actual parameters (or arguments??)
    cout << z << endl;

    //Pass by Address
    int c = 10, d = 20;
    swap(&c, &d);
    cout << c << "," << d << endl;

    //Pass by Reference
    swapRef(c, d);
    cout << c << "," << d << endl;
}


