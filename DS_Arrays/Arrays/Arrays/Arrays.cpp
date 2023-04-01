// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Note use pointer * for the arrays when you are modifying them, and values if not. See different functions...

#include <iostream>
#include <cstdlib>
#include <cstdio>

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
	int *A;
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
	std::cout << std::endl;
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
			//swap(&arr->A[i], &arr->A[0]);
			return i;
		}
	}
	return -1;//Invalid index being returned so the function doesn't give you an index in the array. This is to say it failed.
}

int BinarySearch(struct Array arr, int key)
{
	int l, mid, h;
	l = 0;
	h = arr.length - 1;

	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr.A[mid])
			return mid;
		else if (key < arr.A[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	return -1;
}

int RecursiveBinarySearch(int a[], int l, int h, int key)
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

int Get(struct Array arr, int index)
{
	if (index >= 0 && index < arr.length)
		return arr.A[index];
	return -1;
}

void Set(struct Array* arr, int index, int x)
{
	if (index >= 0 && index < arr->length)
	{
		arr->A[index] = x;
	}
}

int Max(struct Array arr)
{
	int max = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
		if (arr.A[i] > max)
			max = arr.A[i];
	return max;
}


int Min(struct Array arr)
{
	int min = arr.A[0];
	int i;
	for (i = 1; i < arr.length; i++)
		if (arr.A[i] < min)
			min = arr.A[i];
	return min;
}

int Sum(struct Array arr)
{
	int sum = 0;
	int i;
	for (i = 0; i < arr.length; i++)
		sum += arr.A[i];
	return sum;
}

float Avg(struct Array arr)
{
	return (float)Sum(arr) / arr.length;
}

void Reverse(struct Array* arr)
{
	int* B;
	int i, j;
	//Array B should be size of array
	B = (int*)malloc(arr->length * sizeof(int));
	//Copy right of A to left of B
	for (i = arr->length - 1, j = 0; i >= 0; i--, j++)
		B[j] = arr->A[i];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = B[i];
}

void Reverse2(struct Array* arr)
{
	int i, j;
	for (i = 0, j = arr->length - 1; i < j; i++, j--)
	{
		swap(&arr->A[i], &arr->A[j]);
	}
}

void LeftShift(struct Array* arr)
{
	int i;
	for (i = 0; i < arr->length; i++)
		arr->A[i] = arr->A[i + 1];
}

void RightShift(struct Array* arr)
{
	int i;
	for (i = arr->length - 1; i > 0; i--)
		arr->A[i] = arr->A[i - 1];
}

void LeftRotate(struct Array* arr)
{
	int i;
	int temp = arr->A[0];
	for (i = 0; i < arr->length; i++)
		arr->A[i] = arr->A[i + 1];
	arr->A[arr->length - 1] = temp;
}

void RightRotate(struct Array* arr)
{
	int i;
	int temp = arr->A[arr->length - 1];
	for (i = arr->length - 1; i > 0; i--)
		arr->A[i] = arr->A[i - 1];
	arr->A[0] = temp;
}

void InsertSort(struct Array* arr, int x)
{
	int i = arr->length - 1;
	if (arr->length == arr->size)
		return;
	while (i >= 0 && arr->A[i] > x)
	{
		arr->A[i + 1] = arr->A[i];
		i--;
	}
	arr->A[i + 1] = x;
	arr->length++;
}

int isSorted(struct Array arr)
{
	int i;
	for (i = 0; i < arr.length - 1; i++)
	{
		if (arr.A[i] > arr.A[i + 1])
			return 0;
	}
	return 1;//If whole loop never returns 0 or false, return 1 or true
}

void REarrange(struct Array* arr)
{
	int i, j;
	i = 0;
	j = arr->length - 1;

	while (i < j)
	{
		while (arr->A[i] < 0) i++;
		while (arr->A[j] >= 0) j--;
		if (i < j) swap(&arr->A[i], &arr->A[j]);
	}

}

struct Array * Merge(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//Created on Heap

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else
			arr3->A[k++] = arr2->A[j++];
	}
	//After one array finishes
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = arr1->length + arr2->length;
	arr3->size = 10;

	return arr3;
}

struct Array* Union(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//Created on Heap

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			arr3->A[k++] = arr2->A[j++];
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}
	//After one array finishes
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];
	for (; j < arr2->length; j++)
		arr3->A[k++] = arr2->A[j];
	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

struct Array* Intersection(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));

	//Copy common elements
	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			i++;
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			arr3->A[k++] = arr1->A[i++];
			j++;
		}
	}

	arr3->length = k;
	arr3->size = 10;

	return arr3;
}

struct Array* Difference(struct Array* arr1, struct Array* arr2)
{
	int i, j, k;
	i = j = k = 0;
	struct Array* arr3 = (struct Array*)malloc(sizeof(struct Array));//Created on Heap

	while (i < arr1->length && j < arr2->length)
	{
		if (arr1->A[i] < arr2->A[j])
			arr3->A[k++] = arr1->A[i++];
		else if (arr2->A[j] < arr1->A[i])
			j++;
		else
		{
			i++;
			j++;
		}
	}
	for (; i < arr1->length; i++)
		arr3->A[k++] = arr1->A[i];

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

	struct Array arr1;
	int choice;
	int x, index;

	printf("What is the size of the array? ");
	scanf_s("%d", &arr1.size);
	arr1.A = (int *) malloc(arr1.size*sizeof(int));
	//Initalizing the arr with values that are not garbage. 
	arr1.length = arr1.size;

	for (int i = 0; i < arr1.length; i++)
	{
		arr1.A[i] = 0;
	}
	

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
		Insert(&arr1, index, x);
		std::cout << std::endl;
		break;
	case 2: printf("Enter index ");
		scanf_s("%d", &index);
		x = Delete(&arr1, index);
		printf("Deleted Element Is %d\n", x);
		std::cout << std::endl;
		break;
	case 3: printf("Enter element to search ");
		scanf_s("%d", &x);
		index = LinearSearch(&arr1, x);
		printf("Element index %d\n", index);
		std::cout << std::endl;
		break;
	case 4: printf("Sum is %d\n", Sum(arr1));
		std::cout << std::endl;
		break;
	case 5: Display(arr1);
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
