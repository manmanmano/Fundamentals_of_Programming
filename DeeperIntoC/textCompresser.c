#include <stdio.h>
#include <stdlib.h>

char Buf1[81], Buf2[81];

void compressText() {
    for (int i = 0, j = 0, spaceCounter = 0; i < 81; i++) {
        if (Buf1[i] == ' ') {
            spaceCounter++;
        } else {
            spaceCounter = 0;
        }
        if (spaceCounter <= 1) {
            Buf2[j] = Buf1[i];
            j++;
        }
    }
}

int main() {
    printf("This program removes extra spaces from a text.\n");
    printf("Type in some text: ");
    fgets(Buf1, sizeof(Buf1), stdin);
    compressText();
    printf("Sentence before compression: %s", Buf1);
    printf("Sentence after compression: %s", Buf2);
    return 0;
}
