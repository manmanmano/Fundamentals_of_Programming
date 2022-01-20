#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma warning (disable:4996)

typedef struct employee {
	char* pFirstName, * pMiddleName, * pLastName;
	int Brutto, TaxCoefficient, Netto;
}EMPLOYEE;

EMPLOYEE* Exam(char* pInput);

int main()
{
	char input[] = "Donald Fauntleroy Duck 15700;";
	EMPLOYEE* emp = Exam(input);
	if (emp->pMiddleName != NULL)
	{
		printf("Employee's name: %s %s %s\n\nEmployee's brutto income: %d $\n\nTax coefficient: %d %%\n\nEmployee's netto income: %d $\n\n",
			emp->pFirstName, emp->pMiddleName, emp->pLastName, emp->Brutto, emp->TaxCoefficient, emp->Netto);
		free(emp->pMiddleName);
	}
	else
	{
		printf("Employee's name: %s %s\n\nEmployee's brutto income: %d $\n\nTax coefficient: %d %%\n\nEmployee's netto income: %d $\n\n",
			emp->pFirstName, emp->pLastName, emp->Brutto, emp->TaxCoefficient, emp->Netto);
	}
	free(emp->pFirstName);
	free(emp->pLastName);
	free(emp);
	return 0;
}

EMPLOYEE* Exam(char* pInput)
{
	if (!pInput || !*pInput)
	{
		return 0;
	}
	EMPLOYEE* employee = (EMPLOYEE*)malloc(sizeof(EMPLOYEE) + 1);
	char* begin = pInput;
	int scount = 0;
	for (int i = 0; *(pInput + i); i++)
	{
		if (*(pInput + i) == ' ')
		{
			scount++;
		}
	}
	int nWords = scount + 1;
	char* end = strchr(begin, ' ');
	*end = 0;
	employee->pFirstName = (char*)malloc(strlen(begin) + 1);
	strcpy(employee->pFirstName, begin);
	*end = ' ';
	begin = end + 1;
	if (nWords == 3)
	{
		employee->pMiddleName = NULL;
	}
	else
	{
		end = strchr(begin, ' ');
		*end = 0;
		employee->pMiddleName = (char*)malloc(strlen(begin) + 1);
		strcpy(employee->pMiddleName, begin);
		*end = ' ';
		begin = end + 1;
	}
	end = strchr(begin, ' ');
	*end = 0;
	employee->pLastName = (char*)malloc(strlen(begin) + 1);
	strcpy(employee->pLastName, begin);
	*end = ' ';
	begin = end + 1;
	employee->Brutto = atoi(begin);
	if (employee->Brutto > 10000)
	{
		employee->TaxCoefficient = 25;
		employee->Netto = employee->Brutto * (100 - employee->TaxCoefficient) / 100;
	} 
	else if (employee->Brutto >= 7500 && employee->Brutto <= 10000)
	{
		employee->TaxCoefficient = 20;
		employee->Netto = employee->Brutto * (100 - employee->TaxCoefficient) / 100;
	}
	else if (employee->Brutto >= 5000 && employee->Brutto < 7500)
	{
		employee->TaxCoefficient = 15;
		employee->Netto = employee->Brutto * (100 - employee->TaxCoefficient) / 100;
	}
	else
	{
		employee->TaxCoefficient = 0;
		employee->Netto = employee->Brutto * (100 - employee->TaxCoefficient) / 100;
	}
	return employee;
}
