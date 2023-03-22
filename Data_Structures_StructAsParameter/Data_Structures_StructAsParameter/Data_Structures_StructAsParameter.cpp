// Data_Structures_StructAsParameter.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Structs as Parameters

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct Rectangle {
    int length;
    int width;
};

struct Combo {
    int A[5] = {2,4,6,8,10};
    int n = 5;
};

int Area(struct Rectangle r1)
{
    return r1.length * r1.width;
}

void changeLength(struct Rectangle* p)
{
    p->length = 15;
}

struct Rectangle *newRectangle()
{
    struct Rectangle* p;
    p = new Rectangle;

    p->length = 7;
    p->width = 7;

    return p;
}


int main()
{
    struct Rectangle r = { 10, 15 };
    int rectArea = Area(r);//When you pass a struct, all its members come with it.
    cout << rectArea << endl;
    
    changeLength(&r);//Pass by address when changing a value. 
    cout << r.length << endl;

    //Create a new rectangle
    struct Rectangle* ptr = newRectangle();
    cout << "Length: " << ptr->length << endl;
    cout << "Width: " << ptr->width << endl;
}

