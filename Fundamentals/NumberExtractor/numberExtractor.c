#include <stdio.h>
#include <stdlib.h>

int main() {
    char buf[20], text[81];
    int j = 0;
    printf("This program will find a number in your text and see if odd or even.\n");
    printf("Type in some text:\n");
    fgets(text, sizeof(text), stdin);
    for (int i = 0; i < 81; i++) {
        if (text[i] >= '0' && text[i] <= '9') {
            buf[j] = text[i];
            j++;
        }
    }
    int x = atoi(buf);
    printf("The number in the text is: %d\n", x);
    if (x % 2 == 0) {
        printf("%d is even.\n", x);
    } else {
        printf("%d is odd.\n", x);
    }
    return 0;
}
