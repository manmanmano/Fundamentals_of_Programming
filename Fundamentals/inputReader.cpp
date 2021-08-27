#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#define ESC 27

int main() {
    char text[21];
    printf("Type in some text that is less than 21 characters:\n");
    for (int i = 0; i < 21; i++) {
        char c = _getche();
        text[i] = c;
        if (c == ESC) { //if the user presses ESC then quit
            break;
        } 
        if (i > 21) {
            break;
        }
    }
    printf("\n Result is: %s\n", text);
    return 0;
}
