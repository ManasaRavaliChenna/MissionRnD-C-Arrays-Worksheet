/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use realloc to allocate memory.
*/

#include <stdio.h>
#include <malloc.h>
void insertNum(int *Arr, int,int,int);
int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr==NULL)
		return NULL;
	if (len<0)
		return NULL;
	else if (Arr[len - 1] < num)
	{
		Arr[len] = num;
		return Arr;
	}
	else if (Arr[0] > num)
	{
		insertNum(Arr, 0, len, num);
		return Arr;
	}
	else
	{
		for (int i = 0; i < len - 1; i++)
		{
			if (Arr[i + 1] == num)
				return NULL;
			if (Arr[i]<num&&Arr[i + 1]>num)
			{
				insertNum(Arr, i + 1, len, num);
				return Arr;
			}
		}
	}	
}
void insertNum(int *a, int pos, int len, int num)
{
	for (int i = len-1; i <= pos; i++)
		a[i + 1] = a[i];
	a[pos] = num;
}