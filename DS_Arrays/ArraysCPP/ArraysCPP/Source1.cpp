// ArraysCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Re-write the C Program to CPP

#include <iostream>
#include <cstdlib>
#include <cstdio>

void ResizeArrays();
void TwoDArrays();



//ADT - Converted to a Class
class Array
{
private:
	int* A;
	int size;
	int length;
	void swap(int* x, int* y);
public: 
	//Constructor first
	Array()
	{
		size = 10; //minimum size
		length = 0;
		A = new int(size);
	}
	Array(int sz)
	{
		size = sz;
		length = 0;
		A = new int(size);
	}
	//Destructor 
	~Array()
	{
		delete[] A;
	}

	//Include prototypes of functions in the class! 
	void Display();
	void Append(int x);
	void Insert(int index, int x);
	int Delete(int index);
	int LinearSearch(int key);
	int BinarySearch(int key);
	//int RecursiveBinarySearch(int a[], int l, int h, int key);
	int Get(int index);
	void Set(int index, int x);
	int Max();
	int Min();
	int Sum();
	float Avg();
	void Reverse();
	void Reverse2();
	void LeftShift();
	void RightShift();
	void LeftRotate();
	void RightRotate();
	void SortedInsert(int x);
	int isSorted();
	void REarrange();
	Array* Merge(Array arr2);
	Array* Union(Array arr2);
	Array* Intersection(Array arr2);
	Array* Difference(Array arr2);


};

//Don't forget to do ClassName and Scope Resolution on the functions
//Swap elements
void Array::swap(int* x, int* y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}


//ADT - Display all elements of the array
void Array::Display()
{
	int i;
	printf("Elements are: \n");
	for (i = 0; i < length; i++)
		printf("%d ", A[i]);
	std::cout << std::endl;
}

//Add an element to the end of the array
void Array::Append(int x)
{
	//check for space
	if (length < size)
		A[length++] = x;
}

//Add an element to a particular index in the array
void Array::Insert(int index, int x)
{
	//Check if index is valid
	int i;
	if (index >= 0 && index <= length)
	{
		for (i = length; i > index; i--)
			A[i] = A[i - 1];
		A[index] = x;
		length++;
	}
}

//Delete an element at a given index
int Array::Delete(int index)
{
	int x = 0;
	int i;

	if (index >= 0 && index < length)
	{
		x = A[index];
		for (i = index; i < length - 1; i++)
			A[i] = A[i + 1];//Shift the elements
		length--;
		return x;
	}

	return 0;
}

//Linear Search
int Array::LinearSearch(int key)
{
	int i;
	for (i = 0; i < length; i++)
	{
		if (key == A[i])
		{
			//Transposition
			//swap(&arr->A[i], &arr->A[i-1]);
			//return i - 1;


			//Move to Front/Head
			//swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;//Invalid index being returned so the function doesn't give you an index in the array. This is to say it failed.
}

int Array::BinarySearch(int key)
{
	int l, mid, h;
	l = 0;
	h = length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

/*int Array::RecursiveBinarySearch(int a[], int l, int h, int key)
{
	int mid;

	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == a[mid])
			return mid;
		else if (key < a[mid])
			return RecursiveBinarySearch(a, l, mid - 1, key);
		else
			return RecursiveBinarySearch(a, mid + 1, h, key);
	}

	return -1;
}
*/

int Array::Get(int index)
{
	if (index >= 0 && index < length)
		return A[index];
	return -1;
}

void Array::Set(int index, int x)
{
	if (index >= 0 && index < length)
	{
		A[index] = x;
	}
}

int Array::Max()
{
	int max = A[0];
	int i;
	for (i = 1; i < length; i++)
		if (A[i] > max)
			max = A[i];
	return max;
}


int Array::Min()
{
	int min = A[0];
	int i;
	for (i = 1; i < length; i++)
		if (A[i] < min)
			min = A[i];
	return min;
}

int Array::Sum()
{
	int sum = 0;
	int i;
	for (i = 0; i < length; i++)
		sum += A[i];
	return sum;
}

float Array::Avg()
{
	return (float)Sum() / length;
}

void Array::Reverse()
{
	int* B;
	int i, j;
	//Array B should be size of array
	B = new int [length];
	//Copy right of A to left of B
	for (i = length - 1, j = 0; i >= 0; i--, j++)
		B[j] = A[i];
	for (i = 0; i < length; i++)
		A[i] = B[i];

	delete[] B;
}

void Array::Reverse2()
{
	int i, j;
	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		swap(&A[i], &A[j]);
	}
}

void Array::LeftShift()
{
	int i;
	for (i = 0; i < length; i++)
		A[i] = A[i + 1];
}

void Array::RightShift()
{
	int i;
	for (i = length - 1; i > 0; i--)
		A[i] = A[i - 1];
}

void Array::LeftRotate()
{
	int i;
	int temp = A[0];
	for (i = 0; i < length; i++)
		A[i] = A[i + 1];
	A[length - 1] = temp;
}

void Array::RightRotate()
{
	int i;
	int temp = A[length - 1];
	for (i = length - 1; i > 0; i--)
		A[i] = A[i - 1];
	A[0] = temp;
}

void Array::SortedInsert(int x)
{
	int i = length - 1;
	if (length == size)
		return;
	while (i >= 0 && A[i] > x)
	{
		A[i + 1] = A[i];
		i--;
	}
	A[i + 1] = x;
	length++;
}

int Array::isSorted()
{
	int i;
	for (i = 0; i < length - 1; i++)
	{
		if (A[i] > A[i + 1])
			return 0;
	}
	return 1;//If whole loop never returns 0 or false, return 1 or true
}

void Array::REarrange()
{
	int i, j;
	i = 0;
	j = length - 1;

	while (i < j)
	{
		while (i < 0) i++;
		while (j >= 0) j--;
		if (i < j) swap(&A[i], &A[j]);
	}

}

//Since the class is of type array, these don't need struct return types
Array* Array::Merge(Array arr2)//You do need a parameter for the second array though
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array (length + arr2.length);//Created on Heap

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else
			arr3->A[k++] = arr2.A[j++];
	}
	//After one array finishes
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = length + arr2.length;

	return arr3;
}

Array* Array::Union(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);//Created on Heap

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			arr3->A[k++] = arr2.A[j++];
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}
	//After one array finishes
	for (; i < length; i++)
		arr3->A[k++] = A[i];
	for (; j < arr2.length; j++)
		arr3->A[k++] = arr2.A[j];
	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

Array* Array::Intersection(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);

	//Copy common elements
	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			i++;
		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			arr3->A[k++] = A[i++];
			j++;
		}
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

Array* Array::Difference(Array arr2)
{
	int i, j, k;
	i = j = k = 0;
	Array* arr3 = new Array(length + arr2.length);//Created on Heap

	while (i < length && j < arr2.length)
	{
		if (A[i] < arr2.A[j])
			arr3->A[k++] = A[i++];
		else if (arr2.A[j] < A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < length; i++)
		arr3->A[k++] = A[i];

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}


int main()
{	//Functions
	//ResizeArrays();

	//TwoDArrays();

	//Array ADT
	/*struct Array* arr = new Array; { {2, 4, 6, 8, 10}, 10, 5 };
	struct Array arr2 = { {-3, -5, -7, 9, 11, -13, -15, 17, 19}, 18, 9 };

	//Merging Arrays
	struct Array arr3 = { {2, 6, 15, 19, 25}, 10, 5 };
	struct Array arr4 = { {3, 6, 7, 15, 29}, 10, 5 };
	struct Array* arr5;

	//Unsorted Arrays
	struct Array arr6 = { {5, 3, 7, 1, 9}, 10, 5 };
	struct Array arr7 = { {2, 3, 4, 10, 1}, 10, 5 };
	*/



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
	//Insert(arr, 5, 12);
	//printf("%d\n", Delete(&arr, 4));
	//printf("%d\n", LinearSearch(&arr, 10));
	//printf("%d\n", BinarySearch(arr, 6));
	//printf("%d\n", RecursiveBinarySearch(arr.A, 0, arr.length, 5));

	//printf("%d\n", Get(arr, 2));
	//Set(&arr, 0, 15);
	//printf("%d\n", Max(arr));
	//printf("%d\n", Min(arr));
	//printf("%d\n", Sum(arr));
	//printf("%f\n", Avg(arr));

	//Reverse(&arr);
	//Reverse2(&arr);
	//LeftShift(&arr);
	//RightShift(&arr);
	//LeftRotate(&arr);
	//RightRotate(&arr);

	//InsertSort(&arr, 1);
	//printf("%d\n", isSorted(arr));
	//REarrange(&arr2);

	//arr5 = Merge(&arr3, &arr4);

	//arr5 = Union(&arr3, &arr4);
	//arr5 = Intersection(&arr3, &arr4);
	//arr5 = Difference(&arr3, &arr4);

	//Display(*arr);

	Array *arr1;
	int choice, sz;
	int x, index;

	printf("What is the size of the array? ");
	scanf_s("%d", &sz);
	arr1 = new Array(sz);
	//Initalizing the arr with values that are not garbage. 
	//length = size;

	/*for (int i = 0; i < arr1.length; i++)
	{
		arr1.A[i] = 0;
	}*/


	do
	{
		printf("Menu\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Search\n");
		printf("4. Sum\n");
		printf("5. Display\n");
		printf("6. Exit\n");

		printf("Enter Your Choice: ");
		scanf_s("%d", &choice);

		switch (choice)
		{
		case 1: printf("Enter an element and index ");
			scanf_s("%d%d", &x, &index);
			arr1->Insert(index, x);
			std::cout << std::endl;
			break;
		case 2: printf("Enter index ");
			scanf_s("%d", &index);
			x = arr1->Delete(index);
			printf("Deleted Element Is %d\n", x);
			std::cout << std::endl;
			break;
		case 3: printf("Enter element to search ");
			scanf_s("%d", &x);
			index = arr1->LinearSearch(x);
			printf("Element index %d\n", index);
			std::cout << std::endl;
			break;
		case 4: printf("Sum is %d\n", arr1->Sum());
			std::cout << std::endl;
			break;
		case 5: arr1->Display();
			std::cout << std::endl;
		}

	} while (choice < 6);
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
