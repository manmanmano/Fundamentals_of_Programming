#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y, z;
    char line[81];
    printf("Type the first integer: ");
    fgets(line, sizeof(line), stdin);
    x = atoi(line);
    printf("Type the second integer: ");
    fgets(line, sizeof(line), stdin);
    y = atoi(line);
    z = x + y;
    printf("The sum is %d\n", z);
    return 0;
}

//fgets(temp, sizeof(temp), stdin)
