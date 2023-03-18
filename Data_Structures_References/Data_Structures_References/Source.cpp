//Data_Structures References 

#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
	int a = 10;
	int& r = a;//Writing the & when declaring a variable gives a reference. You must initalize a ref at the start. 
	cout << a << endl;
	r++; //A ref is an alias, or another name for a variable. Changing r changes a too 
	cout << r << endl;
	cout << a << endl;
}