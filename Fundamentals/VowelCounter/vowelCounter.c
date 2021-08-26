#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[80], vowels[] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int counter = 0;
        printf("Type in some text: ");
    fgets(line, sizeof(line), stdin);
    for (int i = 0; i < 80; i++) {
        for (int j = 0; j < 6; j++) {
            if (line[i] == vowels[j]) {
                counter++;
            }
        }
    }
    printf("There are %d vowels in your text.\n", counter);
    return 0;
}
