#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 0; i < 50; i++) {
        int r = rand();
        if (r < 500) {
            printf("%d\n", r);
        }
    }
    return 0;
}
