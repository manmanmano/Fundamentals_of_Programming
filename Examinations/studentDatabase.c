#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct Date {
	int day;
	char month[4];
	int year;
}DATE;

typedef struct Student {
	const char* pFirstName, * pLastName, * pNationality;
	DATE Birthdate;
}STUDENT;

int Exam(STUDENT* pStudents, int nStudents, const char* pPattern);

STUDENT students[] =
{
	{"John", "Smith", "Britain", {1, "Feb", 2000}},
	{"Mary", "Weaver", "USA", {2, "Mar", 2001}},
	{"James", "Carpenter", "Canada", {11, "Oct", 2002}},
	{"Elizabeth", "Clerk", "Ireland", {21, "Dec", 2001}}
};

int main()
{
	const char* pToSearch1 = "Carpenter, James born 11 October 2002 from Canada";
	const char* pToSearch2 = "Clerk, Elizabeth born 21 December 2001 from Ireland";
	const char* pToSearch3 = "Neutron, Jimi born 14 May 2001 from Iran";
	const char* pToSearch4 = "Weaver, Mary born 2 March 2001 from USA";
	const char* pToSearch5 = "Hernandez, Diego born 7 January 1997 from Argentina";
	printf(" - CODE %d\n\n\n", Exam(students, 4, pToSearch1));
	printf(" - CODE %d\n\n\n", Exam(students, 4, pToSearch2));
	printf(" - CODE %d\n\n\n", Exam(students, 4, pToSearch3));
	printf(" - CODE %d\n\n\n", Exam(students, 4, pToSearch4));
	printf(" - CODE %d\n\n\n", Exam(students, 4, pToSearch5));
	return 0;
}

int Exam(STUDENT* pStudents, int nStudents, const char* pPattern)
{
	if (!pStudents || !nStudents || !*pPattern || !pPattern)
	{
		printf("Error!");
		return 0;
	}
	char* pPatternCopy = (char*)malloc(strlen(pPattern) + 1);
	strcpy(pPatternCopy, pPattern);
	char* pComma = strchr(pPatternCopy, ',');
	*pComma = 0;
	strcat(pPatternCopy, pComma + 1); //replace terminating 0 with new string to delete comma
	int scount = 0;
	for (char* p = pPatternCopy; 1; ) //terminating 0 at every space
	{
		char* pSpace = strchr(p, ' ');
		if (!pSpace)
		{
			break;
		}
		else
		{
			scount++;
			*pSpace = 0;
			p = pSpace + 1;
		}
	}
	int nWords = scount + 1;
	char** ppTable = (char**)malloc(nWords * sizeof(char*));
	for (int i = 0, iWordBegin = 0; i < nWords; i++) //split the string to search into a table
	{
		int iWordLength = strlen(pPatternCopy + iWordBegin);
		*(ppTable + i) = (char*)malloc(iWordLength + 1);
		strcpy(*(ppTable + i), pPatternCopy + iWordBegin);
		*(pPatternCopy + iWordBegin + iWordLength) = ' ';
		iWordBegin += iWordLength + 1;
	}
	*(*(ppTable + 4) + 3) = 0; //count only the first three bytes of the month
	printf("To search: %s\n", pPattern);
	for (int i = 0; i < nStudents; i++, pStudents++) //compare specified members of the table with members of the struct
	{
		if (!strcmp(pStudents->pFirstName, *(ppTable + 1)) &&
			!strcmp(pStudents->pLastName, *(ppTable + 0)) &&
			!strcmp(pStudents->pNationality, *(ppTable + 7)) &&
			!strcmp(pStudents->Birthdate.month, *(ppTable + 4)) &&
			(pStudents->Birthdate.day == atoi(*(ppTable + 3))) &&
			(pStudents->Birthdate.year == atoi(*(ppTable + 5))))
		{
			printf("\nThe student has been found!");
			return 1;
		}
	}
	printf("\nThe student has not been found!");
	for (int i = 0; i < nWords; i++)
	{
		free(*(ppTable + i));
	}
	free(ppTable);
	free(pPatternCopy);
	return 0;
}
