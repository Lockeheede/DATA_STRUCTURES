// Data_Structures_Pointers.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 3 Pointers. 

#include <iostream>
#include <stdio.h>
using namespace std;

struct Rectangle
{
	int length;
	int width;
};

int main()
{
	int a = 10;
	int* p;//Pointer declaration (you need the *!)
	p = &a;//Address of a stored in pointer
	cout << a << endl;
	printf("Address using pointer: %d\n", p); //a address
	printf("Using pointer: %d\n", *p); //a value. Dereferencing
	printf("Using address: %d\n", &a); //a address


	//Note, I used cout on the address using p and it wasn't the same as the printf with &a even though they are the same. 

	int A[5] = { 2, 4, 6, 8, 10 };
	int* t;
	t = A;//You don't need & with array because it is already an address
	t = &A[0]; //Or you can do this...only when you are index setting. 

	for (int i = 0; i < 5; i++)
		cout << t[i] << endl;//Accessing the values of Array using pointer

	int* r;
	r = (int*)malloc(5 * sizeof(int)); //Access an array on the HEAP. Dynamic allocation.  
	r[0] = 10; r[1] = 15; r[2] = 20; r[3] = 25; r[5] = 30;

	for (int i = 0; i < 5; i++)
		cout << r[i] << endl;

	int* p1;
	p1 = new int[5]; //C++ way of dynamic allocation


	int* p2;
	char* p3;
	float* p4;
	double* p5;
	struct Rectangle* p6;

	cout << sizeof(p2)<<endl;
	cout << sizeof(p3)<<endl;
	cout << sizeof(p4)<<endl;
	cout << sizeof(p5)<<endl; 
	cout << sizeof(p6)<<endl;	

	delete[]p1; //Make sure to delete the allocation to prevent memory leaks. 
	//Dealocatting in C is free(p1); 
}


