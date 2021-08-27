#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    char line[81];
    printf("Type the first integer: ");
    fgets(line, sizeof(line), stdin);
    x = atoi(line);
    printf("Type the second integer: ");
    fgets(line, sizeof(line), stdin);
    y = atoi(line);
    if (x > y) {
        printf("%d is greater than %d", x, y);

    } else if (x < y) {
        printf("%d is less than %d", x, y);
    } else {
        printf("%d is equal with %d", x, y);
    }
    return 0;

}
