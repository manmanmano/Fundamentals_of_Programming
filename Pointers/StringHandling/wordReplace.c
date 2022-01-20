#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning (disable:4996)

char* WordReplace(char*, const char*, const char*);

int main()
{
	char gString[] = "I asked Mary to call me";
	printf("This program replaces the first occurence of a given word with another word in a given string\n");
	printf("The old given string is: %s.\n", gString);
	char* pc = WordReplace(gString, "Mary", "Elizabeth");
	printf("The new given string is: %s.\n", pc);
	return 0;
}

char* WordReplace(char* oldString, const char* pNameToRemove, const char* pNameToCat)
{
	if (!oldString || !pNameToRemove || !pNameToCat || !*oldString || !*pNameToRemove || !*pNameToCat)
	{
		printf("Failed!");
		return 0;
	}
	int lold = strlen(pNameToRemove);
	char* pOldWordBegin = 0;
	for (char* p = oldString; 1; )
	{
		char* fs = strstr(p, pNameToRemove);
		if (fs == 0)
		{
			break;
		}
		else if ((fs == oldString || *(fs - 1) == ' ') && (*(fs + lold) == 0 || *(fs + lold) == ' '))
		{
			pOldWordBegin = fs;
			break;
		}
		else
		{
			p = fs + 1;
		}
	}
	int lnewString = strlen(oldString) - strlen(pNameToRemove) + strlen(pNameToCat);
	char* newString = (char*)malloc(lnewString + 1); // terminating 0 
	strncpy(newString, oldString, (pOldWordBegin - oldString)); // copy the section before the old word
	*(newString + (pOldWordBegin - oldString)) = 0;
	strcat(newString, pNameToCat);
	strcat(newString, pOldWordBegin + lold); // concatenate the rest skipping the old work
	return newString;
}
