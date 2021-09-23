#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const char engAlphabet[] = "abcdefghijklmnopqrstuvwxyz";

int* CharFreqs(char*);

int main() {
	char gString[] = "Zorro stinks and should eat dirt!";
	printf("This programs makes a list of all the english letters occured in a given string.\n");
	printf("The given string is %s", gString);
	int* pi = CharFreqs(gString);
	for (int i = 0; i < strlen(engAlphabet); i++) {
		printf("%c - %d\n", *(engAlphabet + i), *(pi + i));
	}
	free(pi);
	return 0;
}

int* CharFreqs(char* string) {
	if (!string || !*string)  {
		return 0;
	}
	int* pCounters = (int*)calloc(26, sizeof(int));
	for (int i = 0; i < strlen(string); i++)
	{
		*(string + i) = tolower(*(string + i));
		for (int j = 0; j < strlen(engAlphabet); j++) {
			if (*(string + i) == *(engAlphabet + j)) {
				*(pCounters + j) += 1;
				break;
			}
		}
	}
	return pCounters;
}
