#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#pragma warning (disable:4996)

typedef struct date {
	int day;
	char month[4];
	int year;
}DATE;

typedef struct student {
	char* pName, * pCode;
	DATE Date;
	int Mark;
}STUDENT;

STUDENT** Exam(char* pNames, char* pResults, int* pnStudents);

char NameCodes[] = "John Smith 25156IVSB; Mary Weaver 253742ABB; James Carpenter 252422TAF; Elizabeth Clerk 251443MV";
char Results[] = "Elizabeth Clerk 4; Mary Weaver 5; John Smith 1; James Carpenter 3";

int main()
{
	int nStudents;
	STUDENT** student = Exam(NameCodes, Results, &nStudents);
	printf("Student's name\t\tStudent's code\t\tStudent's mark\t\tDate today\t\n");
	for (int i = 0; i < nStudents; i++)
	{
		printf("\n%s\t\t%s\t\t%d\t\t\t%d %s %d\n", 
			(*(student + i))->pName, (*(student + i))->pCode, (*(student + i))->Mark, (*(student + i))->Date.day, (*(student + i))->Date.month, (*(student + i))->Date.year);
	}
	for (int i = 0; i < nStudents; i++)
	{
		free((*(student + i))->pName);
		free((*(student + i))->pCode);
		free((*(student + i)));
	}
	free(student);
	return 0;
}

STUDENT** Exam(char* pNames, char* pResults, int* pnStudents)
{
	if (!pNames || !pResults || !pnStudents || !*pNames || !*pResults || !*pnStudents)
	{
		return 0;
	}
	int scount = 0;
	for (int i = 0; *(pNames + i); i++)
	{
		if (*(pNames + i) == ';')
		{
			scount++;
		}
	}
	*pnStudents = scount + 1;
	STUDENT** student = (STUDENT**)malloc(*pnStudents * sizeof(STUDENT*));
	char* copy = strdup(pNames);
	char* token = strtok(copy, ";");
	struct tm* timeatm;
	time_t now;
	time(&now);
    timeatm = localtime(&now);
	for (int i = 0; token != NULL; i++)
	{
		*(student + i) = (STUDENT*)malloc(sizeof(STUDENT));
		char* delim = strrchr(token, ' ');
		*delim = 0;
		char* name = strpbrk(token, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		(*(student + i))->pName = (char*)malloc(strlen(token) + 1);
		strcpy((*(student + i))->pName, name);
		(*(student + i))->pCode = (char*)malloc(strlen(delim + 1) + 1);
		strcpy((*(student + i))->pCode, delim + 1);
		*delim = ' ';
		token = strtok(NULL, ";");
		char* find = strstr(pResults, (*(student + i))->pName);
		find = strpbrk(find, "0123456789");
		(*(student + i))->Mark = atoi(find);
		(*(student + i))->Date.day = timeatm->tm_mday;
		(*(student + i))->Date.year = timeatm->tm_year + 1900;
		for (int j = 0; j < 12; j++)
		{
			const char* months[] = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
			if (timeatm->tm_mon == j)
			{
				strcpy((*(student + i))->Date.month, *(months + j));
			}
		}
	}
	return student;
}
