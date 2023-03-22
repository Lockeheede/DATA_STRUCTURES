// Data_Structures_CProgramtoCPPClass.cpp : This file contains the 'main' function. Program execution begins and ends there.
// C Program to C++ Class
// This is the introduction to Object Oriented Programming. An Object, it's member values and its behaviors. 

#include <iostream>

using namespace std;

class Rectangle
{
private://By default these are private, but good to say it
	int length;
	int width;

public://Functions, used in order to get access of the private member variables
	Rectangle()
	{
		//Default constructor
		length = 0;
		width = 0;
	}
	Rectangle(int l, int w)
	{
		//Set the length and width to whatever was put in the args.
		length = l;
		width = w;
	}

	int Area() { return length * width; }
	int Perimeter() { return 2 * (length + width); }

	//Setters
	void SetLength(int l) { length = 1; }
	void SetWidth(int w) { width = w; }

	//Getters
	int getLength() { return length; }
	int getWidth() { return width; }

	~Rectangle()
	{
		cout << "Destuctor\n";
	}
};

int main()
{
	int length = 0, width = 0;
	cout << "Enter Length and Width: ";
	cin >> length >> width;
	Rectangle r(length, width);

	int area = r.Area();
	int perimeter = r.Perimeter();
	cout << "Area: " << area << endl;
	cout << "Perimeter: " << perimeter << endl;

}
