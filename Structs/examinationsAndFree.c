#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

typedef struct Date
{
	int day;
	char* pMonth; //full name, locates on its own memory field that must be allocated
	int year;
}DATE;

typedef struct Exam
{
	char* pSubject;
	DATE date;
	int mark;
}EXAM;

int main()
{
	const char* subjectName[] =
	{
		"Networking", "C Programming", "Informatics", "Discrete Mathematics"
	};
	const char* monthName[] =
	{
		"Dec", "Dec", "Dec", "Jan"
	};
	EXAM exams[4] =
	{
		{ 0, {14, 0, 2020}, 5},
		{ 0, {18, 0, 2020}, 4},
		{ 0, {21, 0, 2020}, 5},
		{ 0, {15, 0, 2020}, 3}
	};
	for (int i = 0; i < 4; i++)
	{
		exams[i].pSubject = (char*)malloc(strlen(subjectName[i]) + 1);
		exams[i].date.pMonth = (char*)malloc(strlen(monthName[i]) + 1);
		strcpy(exams[i].pSubject, subjectName[i]);
		strcpy(exams[i].date.pMonth, monthName[i]);
	}
	int nExams = 4;
	int mark_add = 0;
	printf("Your examinations are:\n\n");
	for (int i = 0; i < nExams; i++)
	{
		printf("%s on the %d of %s %d.\n", exams[i].pSubject, exams[i].date.day, exams[i].date.pMonth, exams[i].date.year);
		printf("Your mark is: %d.\n\n", exams[i].mark);
		mark_add += exams[i].mark;
	}
	double average = (double)mark_add / (double)nExams;
	printf("Your average mark is: %lg.\n", average);
	for (int i = 0; i < nExams; i++)
	{
		free(exams[i].pSubject);
		free(exams[i].date.pMonth);
	}
	return 0;
}
