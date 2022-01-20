
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct student {
	char* pName;
	int nMarks, * pMarks; //number of marks and pointer to array of marks
	double AverageMark;
}STUDENT;

STUDENT* Exam(char* pInput, char* pStudentName);

int main()
{
	char input[] = "John Smith: 4, 2, 5, 3; James Farmhand: 1, 4, 3; Jimi Hendrix: 1, 5, 2, 3, 4, 4; Albert Einstein: 5;";
	STUDENT* stud = Exam(input, (char*)("Jimi Hendrix"));
	printf("The student to search is: %s\n\n", stud->pName);
	printf("There are %d marks in the student's database\n\nThe student's marks are: ", stud->nMarks);
	for (int i = 0; i < stud->nMarks; i++)
	{
		printf("%d ", stud->pMarks[i]);
	}
	printf("\n\nThe student's average mark is: %lg\n", stud->AverageMark);
	return 0;
}

STUDENT* Exam(char* pInput, char* pStudentName)
{
	if (!pInput || !*pInput || !pStudentName || !*pStudentName)
	{
		return 0;
	}
	STUDENT* Student = (STUDENT*)malloc(sizeof(STUDENT));
	char* pStudent = strstr(pInput, pStudentName);
	char* end = strchr(pStudent, ':');
	*end = 0;
	Student->pName = (char*)malloc(strlen(pStudentName) + 1);
	strcpy(Student->pName, pStudent); /*Student name*/
	*end = ':';
	Student->nMarks = 0;
	for (int i = 0; *(pStudent + i) != ';'; i++)
	{
		if (*(pStudent + i) >= '0' && *(pStudent + i) <= '9')
		{
			Student->nMarks++; /*Number of marks*/
		}
	}
	Student->pMarks = (int*)calloc(Student->nMarks, sizeof(int));
	double mark_add = 0;
	char* num = pStudent;
	end = strchr(pStudent, ';');
	*end = 0;
	for (int i = 0; i < Student->nMarks; i++)
	{
		num = strpbrk(pStudent, "12345");
		Student->pMarks[i] = atoi(num);
		mark_add += Student->pMarks[i];
		pStudent = num + 1;
	}
	*end = ';';
	Student->AverageMark = mark_add / Student->nMarks; /*Average mark*/
	return Student;
}
