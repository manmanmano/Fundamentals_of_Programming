#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

char** SentenceSplit(char*, int*);
char* CreateRandomSentence(int, int, ...);

int main() {
	int noW;
	printf("This program generates a random sentence and splits it into a table of words.\n");
	char* ps = CreateRandomSentence(5, 3, 6, 4, 1, 2); //pc points to pResult
	printf("The generated random sentence is: %s", ps);
	char** pt = SentenceSplit(ps, &noW);
	for (int i = 0; i < noW; i++) {
		printf("\n%s\n", *(pt + i));
		free(*(pt + i));
	}
	if (pt) {
		free(pt);
	}
	if (ps) {
		free(ps);
	}
	return 0;
}


char* CreateRandomSentence(int nWords, int n1, ...) { // this code is out of scope of this course. 
   // #include "stdarg.h" is needed
   // nWords is the number of words, it is followed by sequence specifying the word lengths
   // nWords may be any positive number
	va_list indic;
	va_start(indic, nWords);
	int nChars = 0, j = 0;
	for (int i = 0; i < nWords; i++, nChars += va_arg(indic, int) + 1);
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char* pResult = (char*)malloc(nChars);
	va_start(indic, nWords);
	for (int i = 0; i < nWords; i++) {
		int nWord = va_arg(indic, int);
		for (int k = 0; k < nWord; k++, *(pResult + j++) = alphabet[rand() % 26]);
		*(pResult + j++) = ' ';
	}
	*(pResult + nChars - 1) = 0;
	return pResult;
}

char** SentenceSplit(char* string, int* nWords) {
	if (!string || !*string) {
		return 0;
	}
	int nSpace = 0;
	int s = strlen(string);
	for (char* p = string; 1;) {
		char* pSpace = strchr(p, ' ');
		if (!pSpace) {
			break;
		}
		else {
			nSpace++;
			*pSpace = 0;
			p = pSpace + 1;
		}
	}
	*nWords = nSpace + 1;
	char** ppOutput = (char**)malloc(*nWords * sizeof(char*));
	for (int i = 0, iWordBegin = 0; i < *nWords; i++) {
		int iWordLength = strlen(string + iWordBegin);
		*(ppOutput + i) = (char*)malloc(iWordLength + 1);
		strcpy(*(ppOutput + i), string + iWordBegin);
		*(string + iWordBegin + iWordLength) = ' ';
		iWordBegin += iWordLength + 1;
	}
	*(string + s) = 0;
	return ppOutput;
}
