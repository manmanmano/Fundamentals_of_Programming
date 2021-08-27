#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[80];
    printf("This program determines if the first character in a text is either a digit or a letter\n");
    printf("Type in some text (max 80 chars): ");
    fgets(line, sizeof(line), stdin);
    if ((line[0] >= 'A' && line[0] <= 'Z') || (line[0] >= 'a' && line[0] <= 'z')) {
        printf("The first letter of the text is a letter.\n");
    } else if ((line[0] >= '0' && line[0] <= '9')) {
        printf("The first letter of the text is a digit.\n");
    } else {
        printf("The first letter of the text is a special character\n");
    }
    return 0;
}
