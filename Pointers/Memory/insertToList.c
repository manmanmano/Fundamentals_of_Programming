#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

int insertName(char*, int, char*);

int main() {
	char namesList[81], newName[81];
	printf("This programs take from input a list of names separated by comma, then inserts a new name to the beginning of the list.\n");
	printf("Type in a list of names separated by comma (no spaces allowed): \n");
	scanf("%s", &namesList);
	printf("Type in the new name to insert: \n");
	scanf("%s", &newName);
	if (insertName(namesList, sizeof(namesList), newName)) {
		printf("The new list of names is: %s.\n", namesList);
	}
	else {
		printf("Error!\n");
	}
	return 0;
}

int insertName(char* pNames, int n, char* pNameToinsert) {
	if (!pNames || !*pNames) {
		return 0;
	}
	if (!pNameToinsert || !*pNameToinsert) {
		return 0;
	}
	int list = 0;
	for (int i = 0; i < n; i++) {//counts the bytes occupied by the existing names
		if (*(pNames + i)) {//array of existing names
			list++;
		}
		else {
			break;
		}
	}
	int newName = 0;
	for (int i = 0; 1; i++) {
		if (*(pNameToinsert + i)) {//counts the bytes of the new name
			newName++;
		}
		else {
			break;
		}
	}
	if (newName > n - list - 2) {//if the new name is bigger than the space remaining in the old list
	                             // 2 = terminating 0 + coma
		return 0; //not enough space
	}
	memmove(pNames + newName + 1, pNames, list + 1); // one for comma
	*(pNames + newName) = ',';
	memcpy(pNames, pNameToinsert, newName);
	return 1;
}
