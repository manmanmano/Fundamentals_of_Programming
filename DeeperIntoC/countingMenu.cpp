#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>

char Buf[81], vowels[6] = { 'a', 'e', 'i', 'o', 'u', 'y' };

int CountVowels();
int CountConsonants();
void Minimizer();

int main()
{
	for (; 1;) {
		printf("\nPress:\n\nv - to count vowels\n\nc - to count consonants\n\nx - to exit\n\n");
		switch (getch()) {
		case 'v':
		case 'V': printf("There are %d vowels in the text.\n", CountVowels());
			break;
		case 'c':
		case 'C': printf("There are %d consonants in the text.\n", CountConsonants());
			break;
		case 'x':
		case 'X': printf("You pressed x. Exiting the program...\n");
			return 0;
		default: break;
		}
	}
	return 0;
}

void Minimizer() {
	for (int i = 0; i < 81 && Buf[i] != 0; i++) {
		Buf[i] = tolower(Buf[i]);
	}
}

int CountVowels() {
	int counter = 0;
	printf("You pressed v. Type in some text:\n");
	fgets(Buf, sizeof(Buf), stdin);
	Minimizer();
	for (int i = 0; i < 81 && Buf[i] != 0; i++) {
		if (isalpha(Buf[i])) {
			for (int j = 0; j < 6; j++) {
				if (Buf[i] == vowels[j]) {
					counter++;
					break;
				}
			}
		}
	}
	return counter;
}

int CountConsonants() {
	int counter = 0;
	printf("You pressed c. Type in some text:\n");
	fgets(Buf, sizeof(Buf), stdin);
	Minimizer();
	for (int i = 0; i < 81 && Buf[i] != 0; i++) {
		if (isalpha(Buf[i])) {
			counter++;
			for (int j = 0; j < 6; j++) {
				if (Buf[i] == vowels[j]) {
					counter--;
					break;
				}
			}
		}
	}
	return counter;
}
