// Dara_Structures_Structs.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 2. Structures

#include <iostream>
#include <stdio.h>

using namespace std;

//Define a structure
struct Rectangle
{
    int length;
    int width;
    char x;
};//Definition doesn't consume memory

int main()
{
    //Declare a variable
    struct Rectangle r1 = { 10, 5 }; //Initalization
    printf("%lu\n", sizeof(r1));//8 bytes because the two variables in the struct are 4 byte variables.

    //Added char x which is 1 byte. But it would change to 12 bytes because at a time it uses 4 bytes in machine code.
    //Example, it is easier for a pharmacist to sell a strip or bottle of tablets even if you are taking 1.
    //It's for accessibility. This is called pairing. Taking extra memory to let the machine read it properly. 

    cout << r1.length << endl; //accessing member variables.
    cout << r1.width << endl;

    r1.length = 20; //Assigning variables.
    r1.width += 15;

    cout << r1.length << endl; //accessing member variables.
    cout << r1.width << endl;
}

