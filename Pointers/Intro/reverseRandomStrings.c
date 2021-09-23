#include <stdio.h>
#include <stdlib.h>

char *CreateRandomString(int n);
char *ReverseRandomString(char*);

int main() {
    int n;
    char line[81], *pc;
    printf("This program will reverse a random string.\n");
    printf("Please type in the length of the string: ");
    fgets(line, sizeof(line), stdin);
    n = atoi(line);
    pc = CreateRandomString(n);
    printf("The original string is %s.\n", pc);
    printf("The reversed string is %s. \n", ReverseRandomString(pc));
    free(pc);
    return 0;
}

char *CreateRandomString(int n) {
	const char alphabet[] = "abcdefghijklmnopqrstuvwxyz";
	char* pResult = (char*)malloc(n + 1); // n + 1 for terminating 0
	for (int i = 0; i < n; i++) { // n is the input by user 
		*(pResult + i) = alphabet[rand() % 26]; //Result[i] = ...
	}
	*(pResult + n) = 0; //terminating zero
	return pResult;
}

char *ReverseRandomString(char *string) {
    int n = 0;
    for (int i = 0; *(string + i); i++, n++); //count the letters inside the string pc
    char *reversed = (char*)malloc(n + 1);
    for (int i = 0, j = n - 1; i < n; i++, j--) {
        *(reversed + i) = *(string + j); //pc + n - 1 points at the first byte of last char pt
    }
    *(reversed + n) = 0;
    return reversed;
}
