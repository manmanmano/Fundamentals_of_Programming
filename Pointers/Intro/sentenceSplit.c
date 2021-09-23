#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

char** sentenceSplit(char*, int*);
char* createRandomsentence(int, int, ...);

int main() {
	int noW;
	printf("This program generates a random sentence and splits it into a table of words.\n");
	char* ps = createRandomsentence(5, 3, 6, 4, 1, 2); //pc points to pResult
	printf("The generated random sentence is: %s", ps);
	char** pt = sentenceSplit(ps, &noW);
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

char* createRandomsentence(int nWords, int nWord1, ...) {
	va_list indic;
	va_start(indic, nWords);
	int nChars = 0, j = 0;
	for (int i = 0; i < nWords; i++, nChars += va_arg(indic, int) + 1);
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char* pResult = (char*)malloc(nChars);
	va_start(indic, nWords);
	for (int i = 0; i < nWords; i++) {
		int nWord = va_arg(indic, int);
		for (int k = 0; k < nWord; k++, *(pResult + j++) = alphabet[rand()%26]);
		*(pResult + j++) = ' ';
	}
	*(pResult + nChars - 1) = 0;
	return pResult; //pResult returns a string of random words
}

char** sentenceSplit(char* string, int* noW) {//generated string and the number of words
	if (!string || !*string) {
		return 0;
	}
	int nSpace = 0;
	for (int i = 0; *(string + i); i++) {
		if (*(string + i) == ' ') {
			nSpace++;
		}
	}
	*noW = nSpace + 1;
	char** ppOutput = (char**)malloc(*noW * sizeof(char*));
	for (int i = 0, iWordBegin = 0; i < *noW; i++) {
		int nWord = 0;
		for (int j = iWordBegin; *(string + j) && *(string + j) != ' '; j++, nWord++);
		*(ppOutput + i) = (char*)malloc(nWord + 1); //nWord is the same as nColumns
		for (int k = 0; k < nWord; k++) {
			*(*(ppOutput + i) + k) = *(string + iWordBegin + k);
		}
		*(*(ppOutput + i) + nWord) = 0;
		iWordBegin += nWord + 1; //to start from next word
	}
	return ppOutput;
}
