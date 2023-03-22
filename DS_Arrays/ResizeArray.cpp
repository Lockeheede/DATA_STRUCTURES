#include <stdio.h>
#include <stdlib.h>

int main()
{
	int *p, *q;
	int i;
	p = new int [5];
	p[0] = 2;
	p[1] = 4;
	p[3] = 6; 
	p[4] = 8;
	p[5] = 10;
	
	q = mew int [10];
	
	for (i = 0; i < 5; i++)
		printf("%d \n", p[i];
	
	return 0;
}