// Data_Structures_StructAndFunc.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Struct and Funct. 

#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int width;
};

void Initialize(struct Rectangle *r1, int l, int w)
{
    r1->length = l;
    r1->width = w;
}

int Area(struct Rectangle r1)
{
    return r1.length * r1.width;
}

int Perimeter(struct Rectangle r1)
{
    int p;
    p = 2 * (r1.length + r1.width);
    return p;
}

int main()
{
    struct Rectangle r;

    printf("Enter the Length and Width: ");
    cin >> r.length >> r.width;

    Initialize(&r, r.length, r.width);
    int a = Area(r);
    int p = Perimeter(r);

    cout << "Area: " << a << "\nPerimeter: " << p << endl;
}

