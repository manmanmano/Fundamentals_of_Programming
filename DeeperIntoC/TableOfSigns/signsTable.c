#include <stdio.h>
#include <stdlib.h>

char Table[5][5];

void createTable() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (Table[i] == Table[j]) {
                Table[i][j] = '*';
            } else if (Table[i] < Table[j]) {
                Table[i][j] = '+';
            } else {
                Table[i][j] = '-';
            }
        }
    }
}

int main() {
    createTable();
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%c", Table[i][j]);
        }
        printf("\n");
    }
}
