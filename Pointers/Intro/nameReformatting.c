#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char* createRandomName(int n1, int n2);
char* reformatName(char*);

int main() {
    int a, b; //a - number of char in the first name, b - chars in the last name
    char line[81], *pc;
    printf("This program will generate a full name and reformat it.\n");
    printf("Please input how many characters you want to be in the last name: ");
    fgets(line, sizeof(line), stdin);
    a = atoi(line);
    printf("Please input how many characters you want to be in the last name: ");
    fgets(line, sizeof(line), stdin);
    b = atoi(line);
    pc = createRandomName(a, b);
    printf("The name before reformatting is %s.\n", pc);
    char* pcc = reformatName(pc);
    printf("The name after reformatting is %s.\n", pcc);
    free(pc);
    free(pcc);
    return 0;
}


char* createRandomName(int n1, int n2) {//n1 - given name; n2 - length of family name
	if (n1 <= 0 || n2 <= 0) {
		return 0;
	}
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char* pResult = (char*)malloc(n1 + n2 + 2); //names + space + terminating 0
	for (int i = 0; i < n1; i++) {
		*(pResult + i) = alphabet[rand() % 26];
	}
	*pResult = toupper(*pResult);
	*(pResult + n1) = ' ';
	for (int i = 0; i < n2; i++) {
		*(pResult + n1 + 1 + i) = alphabet[rand() % 26];
	}
	*(pResult + n1 + 1) = toupper(*(pResult + n1 + 1));
	*(pResult + n1 + n2 + 1) = 0;
	return pResult;
}

char* reformatName(char* fullname) {
	int n = 0;
	for (; *(fullname + n); n++); // counts bytes inside fullname
	int spaceIndex = 0;
	for (int i = 0; i < n; i++) {
		if (*(fullname + i) == ' ') {
			spaceIndex = i;
		}
	}
	char* pReformat = (char*)malloc(n + 2); //coma and space
	int i = spaceIndex, j = 0;
	for (; *(fullname + i) != 0; i++, j++) {
		*(pReformat + j) = *(fullname + i); //first name into pReformat
	}
	*(pReformat + j) = ',';
	*(pReformat + j + 1) = ' ';
	j = j + 2;
	int h = 0;
	for (; *(fullname + h) != ' '; h++, j++) {
		*(pReformat + j) = *(fullname + h); //second name into pReformat
	}
	*(pReformat + j) = 0;
	return pReformat;
}
