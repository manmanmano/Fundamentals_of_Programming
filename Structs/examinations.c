
#include <stdio.h>
#include <stdlib.h>

typedef struct Date
{
	int day;
	char month[4];
	int year;
}DATE;

typedef struct Exam
{
	const char* pSubject;
	DATE date;
	int mark;
}EXAM;

int main()
{
	EXAM exams[4] =
	{
		{"Networking", {14, "Dec", 2020}, 5},
		{"C Programming", {18, "Dec", 2020}, 4},
		{"Informatics", {21, "Dec", 2020}, 5},
		{"Mathematics", {15, "Jan", 2020}, 3}
	};
	int nExams = 4;
	int mark_add = 0;
	printf("Your examinations are:\n\n");
	for (int i = 0; i < nExams; i++)
	{
		printf("%s on the %d of %s %d.\n", exams[i].pSubject, exams[i].date.day, exams[i].date.month, exams[i].date.year);
		printf("Your mark is: %d.\n\n", exams[i].mark);
		mark_add += exams[i].mark;
	}
	double average = (double)mark_add / (double)nExams;
	printf("Your average mark is: %lg.\n", average);
	return 0;
}
