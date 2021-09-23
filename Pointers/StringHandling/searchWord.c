#include <stdio.h>
#include <string.h>

int WordSearch(char*, const char*);

int main() {
	char gString[] = "lol lol xd I thought you loved cows lol xd";
	printf("This program counts the occurrences of a word in a given string.\n");
	printf("This is the given string: %s.\n", gString);
    char* gWord = "lol";
	int pi = WordSearch(gString, gWord);
	printf("The word %s occurred %d times.\n", gWord, pi);
	return 0;
}

int WordSearch(char* string, const char* pWord) {
	if (!string || !*string || !pWord || !*pWord) {
		return -1;
	}
	int wordLength = strlen(pWord), wordCounter = 0;
	for (char* p = string; 1; ) {
		char* fs = strstr(p, pWord); //fs for found substring
		if (!fs) {
			break;
		}
		else if ((fs == string || *(fs - 1) == ' ') && (*(fs + wordLength) == 0 || *(fs + wordLength) == ' ')) {
			wordCounter++;
			p = strchr(fs, ' ');
			if (!p) {
				break;
			}
		}
		p++;
	}
	return wordCounter;
}
