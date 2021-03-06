/*
OVERVIEW:  You are given scores for students of a class in alphabetical order. Write a function that sorts these scores in descending order.
Input is array of structures of type student (each student has name and score).
E.g.: If input is [ { "stud1", 20 }, { "stud2", 30 }, { "stud3", 40 } ] (three students with marks 20, 30 , 40).
Output for this will be [ { "stud3", 40 }, { "stud2", 30 }, { "stud1", 20 } ]

INPUTS: Array of structures of type student, length of array.

OUTPUT: Sort the array in descending order of scores.

ERROR CASES: Return NULL for invalid Inputs.

NOTES:
*/

#include <stdio.h>

struct student
{
	char name[10];
	int score;
};
void swap(struct student*, struct student*);
void * scoresDescendingSort(struct student *students, int len) 
{
	int swapped = 1,k=1;
	if (students == NULL || len < 0)
		return NULL;
	if (len == 1)
	{
		if (students[0].score < 0)
			return NULL;
		else
			return students;
	}
	else if (len == 2)
	{
		if ((students[0].score < 0) || (students[1].score < 0))
			return NULL;
		if (students[0].score < students[1].score)
			swap(&students[0], &students[1]);
		else
			return students;
	}
	else
	{
		while (swapped == 1)
		{
			swapped = 0;
			for (int i = 0; i < len - 1; i++)
			{

				if (k == 1 && ((students[i].score < 0) || (students[i + 1].score < 0)))
					return NULL;
				if (students[i].score < students[i + 1].score)
				{
					swapped = 1;
					swap(&students[i], &students[i + 1]);
				}
			}
		}
		return students;
	}
}
void swap(struct student* a, struct student* b)
{
	student temp = *a;
	*a = *b;
	*b = temp;
}