#include <stdio.h>
#include <conio.h>

int main() {
    char vowels[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int counters[6] = {0, 0, 0, 0, 0, 0};
    printf("Type in some text: \n");
    while (1) {
        char c = _getche();
        if (c == 27) {
            break;
        }
        for (int j = 0; j < 6; j++) {
            if (c == vowels[j]) {
                counters[j] += 1;
                break;
            }
        }
    }
    printf("\n");
    for (int i = 0; i < 6; i++) {
        printf("%c: %d\n", vowels[i], counters[i]);
    }
    return 0;
}
