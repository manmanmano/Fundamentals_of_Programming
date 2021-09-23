#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int CharFreq(char*, char);

int main() {
	char gString[] = "pneumonoultramicroscopicsilicovolcanoconiosis";
	printf("This program counts the number of occurences of a character in a given string.\n");
	printf("The given string is %s.\n", gString);
    char chosenLetter = 'o';
	int x = CharFreq(gString, chosenLetter);
	printf("The letter %c occured %d times.",chosenLetter, x);
	return 0;
}

int CharFreq(char* string, char x) {
	if (!string || !*string) {
		return 0;
	}
	int nChar = 0;
	for (char* p = string; 1;) {
		char* pChar = strchr(p, x);
		if (!pChar) {
			break;
		}
		else {
			nChar++;
			p = pChar + 1;
		}
	}
	return nChar;
}
