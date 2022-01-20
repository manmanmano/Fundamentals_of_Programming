#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

typedef struct Date {
	int day;
	char month[4];
	int year;
}DATE;

typedef struct Exam {
	char* pSubject;
	DATE date;
	int mark;
}EXAM;

EXAM** MySession(int*);

int main()
{
	int nExams;
	EXAM** pMyExams = MySession(&nExams);
	int mark_add = 0;
	printf("Your examinations are:\n\n");
	for (int i = 0; i < nExams; i++)
	{
		printf("%s on the %d of %s %d.\n", (*(pMyExams + i))->pSubject, (*(pMyExams + i))->date.day, (*(pMyExams + i))->date.month, (*(pMyExams + i))->date.year);
		printf("Your mark is: %d.\n\n", (*(pMyExams + i))->mark);
		mark_add += (*(pMyExams + i))->mark;
	}
	double average = (double)mark_add / (double)nExams;
	printf("Your average mark is: %lg.\n", average);
	for (int i = 0; i < nExams; i++)
	{
		free((*(pMyExams + i))->pSubject);
	}
	free(pMyExams);
	return 0;
}

EXAM** MySession(int* pnExams)
{
	const char* Subjects[] =
	{
		"Networking", "C Programming", "Informatics", "Discrete Mathematics"
	};
	DATE dates[] =
	{
		{14, "Dec", 2020},
		{18, "Dec", 2020},
		{21, "Dec", 2020},
		{15, "Jan", 2020}
	};
	int marks[] = { 5, 4, 5, 3 };
	*pnExams = 4;
	EXAM** pExams = (EXAM**)malloc(*pnExams * sizeof(EXAM*));
	for (int i = 0; i < *pnExams; i++)
	{
		*(pExams + i) = (EXAM*)malloc(*pnExams * sizeof(EXAM));
		(*(pExams + i))->pSubject = (char*)malloc(strlen(Subjects[i]) + 1);
		strcpy((*(pExams + i))->pSubject, Subjects[i]);
		(*(pExams + i))->date = dates[i];
		(*(pExams + i))->mark = marks[i];
	}
	return pExams;
}
