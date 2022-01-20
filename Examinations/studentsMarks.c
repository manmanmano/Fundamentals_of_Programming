#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning(disable:4996)

typedef struct student
{
	char* pName;
	char* pCode;
	int mMathematics, mPhysics, mChemistry;
	double Average;
}STUDENT;

STUDENT* Exam(char* pStudents, char* pMathematics, char* pPhysics, char* pChemistry);

int main()
{
	char pStudents[] = "John Smith 25156IVSB; Mary Weaver 253742AAB; James Carpenter 252422TAF; Elizabeth Clerk 251443MV";
	char pMathematics[] = "John Smith 5; Mary Weaver 4; James Carpenter 4; Elizabeth Clerk 2";
	char pPhysics[] = "Mary Weaver 3; John Smith 5; Elizabeth Clerk 2; James Carpenter 2";
	char pChemistry[] = "Elizabeth Clerk 4; Mary Weaver 5; John Smith 1; James Carpenter 3";
	STUDENT* student = Exam(pStudents, pMathematics, pPhysics, pChemistry);
	printf("The best student is: %s %s\n\nThe student's average mark is: %lg\n", student->pName, student->pCode, student->Average);
	return 0;
}

STUDENT* Exam(char* pStudents, char* pMathematics, char* pPhysics, char* pChemistry)
{
	if (!pStudents || !*pStudents || !pMathematics || !*pMathematics || !pPhysics || !*pPhysics || !pChemistry || !*pChemistry)
	{
		return 0;
	}
	int semicounter = 0;
	for (int i = 0; *(pStudents + i); i++)
	{
		if (*(pStudents + i) == ';')
		{
			semicounter++;
		}
	}
	int nStudents = semicounter + 1, theChosenOne = 0;
	STUDENT* student = (STUDENT*)malloc(sizeof(STUDENT) * nStudents);
	char* dup = strdup(pStudents), * token = strtok(dup, ";");
	double max = 0;
	for (int i = 0; token; i++)
	{
		char* delim = strrchr(token, ' ');
		*delim = 0;
		char* found = strpbrk(token, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
		(student + i)->pName = (char*)malloc(strlen(found) + 1);
		strcpy((student + i)->pName, found);
		(student + i)->pCode = (char*)malloc(strlen(delim + 1) + 1);
		strcpy((student + i)->pCode, delim + 1);
		*delim = ' ';
		found = strstr(pPhysics, (student + i)->pName);
		found = strpbrk(found, "12345");
		(student + i)->mPhysics = atoi(found);
		found = strstr(pChemistry, (student + i)->pName);
		found = strpbrk(found, "12345");
		(student + i)->mChemistry = atoi(found);
		found = strstr(pMathematics, (student + i)->pName);
		found = strpbrk(found, "12345");
		(student + i)->mMathematics = atoi(found);
		(student + i)->Average = ((student + i)->mMathematics + (student + i)->mChemistry + (student + i)->mPhysics) / 3;
		if ((student + i)->Average > max)
		{
			max = (student + i)->Average;
			theChosenOne = i;
		}
		token = strtok(NULL, ";");
	}
	return (student + theChosenOne);
}
