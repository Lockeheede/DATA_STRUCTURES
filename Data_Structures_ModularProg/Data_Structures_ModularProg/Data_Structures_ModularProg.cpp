// Data_Structures_ModularProg.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Modular/Procedural Programming

#include <iostream>

using namespace std;

int Area(int length, int width)
{
	return length * width;
}

int Perimeter(int length, int width)
{
	return 2 * (length + width);
}

int main()
{
	int length = 0, width = 0;

	printf("Enter length and width: ");
	cin >> length >> width;

	int area = Area(length, width);
	int perimeter = Perimeter(length, width);

	printf("Area: %d\nPerimeter: %d", area, perimeter);
}
