/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>
void swap(int*, int*);
void swap(int* b, int* a)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (len <= 1||Arr==NULL)
		return NULL;
	else if (Arr[0] > Arr[1] && Arr[len - 1] < Arr[len - 2])
		swap(&Arr[0], &Arr[len - 1]);
	else
	{
		int p1=-1, p2=-1;
		for (int i = 0, j = len - 1; i < len - 1, j > 0; i++, j--)
		{
			if (Arr[i] > Arr[i + 1])
			{
				p1 = i;
				i = len;
			}
			if (Arr[j - 1] > Arr[j])
			{
				p2 = j;
				j = -1;
			}
		}
		if (p1 == -1 && p2 == -1)
			return NULL;
		else
			swap(&Arr[p1], &Arr[p2]);
	}
	return NULL;
}