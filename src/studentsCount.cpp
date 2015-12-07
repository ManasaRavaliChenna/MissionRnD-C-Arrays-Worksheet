
/*
OVERVIEW:  Write a function that takes ascending sorted student's score array and tells how many number of students got more marks and how many students got less marks than the given student.
E.g.: Input array: [10, 20, 30, 40, 50], score: 30, lessCount value is 2 (10, 20 are less than 30), moreCount value is 2 (40, 50 are greater than 30).

INPUTS: Ascending sorted student marks array, length of the array, one student score, lessCount and moreCount are to be
used to store final results.

OUTPUT: Update lessCount and moreCount with number of students less than and more than given score.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>

void * studentsCount(int *Arr, int len, int score, int *lessCount, int *moreCount) 
{
	*lessCount = 0;
	*moreCount = 0;
	if (len < 0 || Arr == NULL)
		return NULL;
	int l = 0, m, h = len, pos = 0;
	while (l <= h)
	{
		m = (l + h) / 2;
		if (Arr[m] == score)
		{
			if (Arr[m + 1] == score)
			{
				*lessCount = 0;
				*moreCount = 0;
				break;
			}
			else
			{
				*lessCount = m;
				*moreCount = len - m - 1;
			}
			break;
		}
		else if (Arr[m]<score&&Arr[m + 1]>score)
		{
			*lessCount = m + 1;
			*moreCount = len - m - 1;
			break;
		}
		else if (Arr[m] < score)
			l = m + 1;
		else
			h = m - 1;
	}
	if (h < 0)
	{
		*lessCount = 0;
		*moreCount = len;
	}
	else if (l>len)
	{
		*lessCount = len;
		*moreCount = 0;
	}
}
