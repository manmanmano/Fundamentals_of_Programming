#include <stdio.h>
#include <stdlib.h>

int main() {
    int Rand[50], max = 0;
    for (int i = 0; i < 50; i++) {
        Rand[i] = rand();
        printf("%d\n", Rand[i]);
        if (max < Rand[i]) {
            max = Rand[i];
        }
    }
    printf("The maximum pseudo random integer is %d.\n", max);
    return 0;
}
