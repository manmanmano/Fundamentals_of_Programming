#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[100];
    int x = 0;
    printf("Type in an integer: ");
    fgets(line, sizeof(line), stdin);
    x = atoi(line);
    if (x % 2 == 0) {
        printf("This number is even.\n");
    } else {
        printf("This number is odd.\n");
    }
    return 0;
}
