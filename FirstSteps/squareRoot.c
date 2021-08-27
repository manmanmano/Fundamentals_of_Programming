#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double a, b, c, x1, x2;
    char line[100];
    printf("Type in the value of a: ");
    fgets(line, sizeof(line), stdin);
    a = atof(line);
    printf("Type in the value of b: ");
    if (a == 0) {
        printf("The value of a cannot be 0!\n");
        return 0;
    }
    fgets(line, sizeof(line), stdin);
    b = atof(line);
    printf("Type in the value of c: ");
    fgets(line, sizeof(line), stdin);
    c = atof(line);
    if (b * b - 4 * a * c < 0) {
        printf("The equation has complex roots!\n");
        return 0;
    }
   x1 = (-b - (sqrt((b * b) - (4 * a * c)))) / (2 * a);
   x2 = (-b + (sqrt((b * b) - (4 * a * c)))) / (2 * a);
   printf("The calculated roots are %lg and %lg.\n",  x1, x2);
}
