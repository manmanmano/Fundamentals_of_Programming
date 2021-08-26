#include <stdio.h>
#include <stdlib.h>

int MaxOfThree(int x, int y, int z) {
    if (x > y && x > z) 
        return x;
    else if (y > x && y > z)
        return y;
    else 
        return z;
}

int main() {
    char buf[21];
    printf("This programs returns the biggest of three numbers.\n");
    printf("Type in your first number: ");
    fgets(buf, sizeof(buf), stdin);
    int x = atoi(buf);
    printf("Type in your second number: ");
    fgets(buf, sizeof(buf), stdin);
    int y = atoi(buf);
    printf("Type in your third number: ");
    fgets(buf, sizeof(buf), stdin);
    int z = atoi(buf);
    printf("Your three numbers are: %d, %d, and %d.\n", x, y, z);
    printf("The biggest of the given three numbers is %d.\n", MaxOfThree(x, y, z));
    return 0;
}
