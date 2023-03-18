// Data_Structures_PointerToStruct.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Pointer to Struct

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int width;
};

int main()
{
    struct Rectangle r = { 15, 10 };//Note in C++, you don't need to put struct first.
    struct Rectangle* p = &r;//Point to the struct

    p->length = 20;//Use arrow operator to assign members in a struct using a pointer
    cout << p->length << endl;

    //Example: Dynamically allocating a struct
    Rectangle* t;
    t = (struct Rectangle*)malloc(sizeof(struct Rectangle));

    t->width = 15;//This is not for r, it is for a dynamically allocated variable. 
    cout << t->width << endl;


}

