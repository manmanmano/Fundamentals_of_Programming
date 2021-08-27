#include <stdio.h>
#include <stdlib.h>

int main() {
    char line[80];
    printf("Type in some text containg english letters (max 80 characters): ");
    fgets(line, sizeof(line), stdin);
    int aCounter = 0;
    for (int i = 0; i < 80; i++) {
        if ((line[i] >= 'A' && line[i] <= 'Z') || (line[i] >= 'a' && line[i] <= 'z')) {
            if (line[i] == 'a' || line[i] == 'A') {
                aCounter++;
            }
        } else if ((line[i] == '!' && line[i] == '@') || (line[i] == '[' && line[i] == '`')
                || (line[i] >= '0' && line[i] <= '9')) {
            printf("Illegal input!\n");
            return 1;
        }
    }
    printf("There are %d a's / A's in your text.\n", aCounter);
    return 0;
}
