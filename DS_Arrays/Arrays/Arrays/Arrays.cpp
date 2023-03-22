// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Note use pointer * for the arrays when you are modifying them, and values if not. See different functions...

#include <iostream>

void ResizeArrays();
void TwoDArrays();

//Swap elements
void swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

//ADT
struct Array
{
	int A[10];
	int size;
	int length;
};

//ADT - Display all elements of the array
void Display(struct Array arr)
{
	int i;
	printf("Elements are: \n");
	for (i = 0; i < arr.length; i++)
		printf("%d ", arr.A[i]);
}

//Add an element to the end of the array
void Append(struct Array* arr, int x)
{
	//check for space
	if (arr->length < arr->size)
		arr->A[arr->length++] = x;
}

//Add an element to a particular index in the array
void Insert(struct Array *arr, int index, int x)
{
	//Check if index is valid
	int i;
	if (index >= 0 && index <= arr->length)
	{
		for (i = arr->length; i > index; i--)
			arr->A[i] = arr->A[i - 1];
		arr->A[index] = x;
		arr->length++;
	}
}

//Delete an element at a given index
int Delete(struct Array* arr, int index)
{
	int x = 0;
	int i;

	if (index >= 0 && index < arr->length)
	{
		x = arr->A[index];
		for (i = index; i < arr->length - 1; i++)
			arr->A[i] = arr->A[i + 1];//Shift the elements
		arr->length--;
		return x;
	}

	return 0;
}

//Linear Search
int LinearSearch(struct Array *arr, int key)
{
	int i;
	for (i = 0; i < arr->length; i++)
	{
		if (key == arr->A[i])
		{
			//Transposition
			//swap(&arr->A[i], &arr->A[i-1]);
			//return i - 1;
			
			
			//Move to Front/Head
			swap(&arr->A[i], &arr->A[0]);
			return 0;
		}
	}
	return -1;//Invalid index
}


int main()
{	//Functions
	//ResizeArrays();
	
	//TwoDArrays();
	
	//Array ADT
	struct Array arr = { {2,4,6,8,10},10,5 };
	
	/*Dynamically Create the Array. Use this with ADT
	int n, i;
	printf("Enter Size of an array: ");
	scanf_s("%d", &arr.size);
	arr.A = new int[arr.size];
	arr.length = 0;
	printf("Enter number of numbers: ");
	scanf_s("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Enter element #%d: ", i);
		scanf_s("%d", &arr.A[i]);
	}
	arr.length = n;*/

	//Append(&arr, 12);
	//Insert(&arr, 5, 12);
	//printf("%d\n", Delete(&arr, 4));
	printf("%d\n", LinearSearch(&arr, 10));
	Display(arr);
}

void ResizeArrays()
{
	int* p, * q;
	int i;
	p = new int[5];
	p[0] = 2;
	p[1] = 4;
	p[2] = 6;
	p[3] = 8;
	p[4] = 10;

	q = new int[10];

	for (i = 0; i < 5; i++)
		printf("%d \n", p[i]);

	//Set first 5 of q array to first 5 of p array.
	for (i = 0; i < 5; i++)
		q[i] = p[i];

	//Delete the p array. Set p to q. Make q NULL
	delete[]p;
	p = q;
	q = NULL;


	p[5] = 12;
	p[6] = 14;
	p[7] = 15;
	p[8] = 16;
	p[9] = 17;

	printf("\n");

	for (i = 0; i < 10; i++)
		printf("%d \n", p[i]);

	delete[] p;
}
void TwoDArrays()
{
	int A[3][4] = { {2, 4, 6, 8}, {1,2,3,4}, {1,3,5,7} };//Created in the stack

	int* B[3];
	B[0] = new int[4];//Created in the heap. Memory dynamically allocated
	B[1] = new int[4];
	B[2] = new int[4];

	int** C;//All inside the heap
	C = new int* [3];
	C[0] = new int[4];
	C[1] = new int[4];
	C[2] = new int[4];

	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", A[i][j]);
		printf("\n");
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", B[i][j]);
		printf("\n");
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%d ", C[i][j]);
		printf("\n");
	}
}
