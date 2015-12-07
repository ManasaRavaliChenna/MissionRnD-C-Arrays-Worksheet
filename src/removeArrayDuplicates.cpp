/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

INPUTS: Integer array and length of the array.

OUTPUT: Update input array by removing duplicate values.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/

#include <stdio.h>

void * removeArrayDuplicates(int *Arr, int len)
{
	int ptr = 0, rep = 0;
	if (len == 0 || len<0 || Arr == NULL)
		return NULL;
	else
	{
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < ptr; j++)
			{
				if (Arr[j] == Arr[i])
				{
					//printf("l%d %dl ", Arr[j], j);
					rep++;
					break;
				}
			}
			if (rep == 0)
				Arr[ptr++] = Arr[i];
			rep = 0;
		}
	}
	return Arr;
}