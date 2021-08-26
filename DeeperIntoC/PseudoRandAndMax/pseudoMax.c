#include <stdio.h>
#include <stdlib.h>

#define TOO_BIG 1
#define TOO_SMALL 2

int RandVal[100];

int GetRandArray(int x) {
    if (x <= 0) {
        printf("Error! Too small!\n");
        return TOO_SMALL;
    } else if (x > 100) {
        printf("Error! Too large!\n");
        return TOO_BIG;
    }
    int max = 0;
    printf("Printing random values...\n");  
    for (int i = 0; i < x; i++) {
        RandVal[i] = rand();
        printf("%d\n", RandVal[i]);
        if (RandVal[i] > max) {
            max = RandVal[i];
        }
    }
    return max;
}

int main() {
    char buf[21];
    printf("This programs generates x number of random values and returns the maximum.\n");
    printf("Please type the desired amount of numbers to be generated (1 - 100): ");
    fgets(buf, sizeof(buf), stdin);
    int x = atoi(buf);
    int randMax = GetRandArray(x);
    if (randMax == 1 || randMax == 2) {
        return 1;
    }
    printf("The maximum random value is: %d.\n", randMax);
    return 0;
}
