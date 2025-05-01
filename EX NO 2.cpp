#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void prepareKey(char key[], char keyTable[SIZE][SIZE]) {
    int dict[26] = {0};
    int i, j, k = 0;

    for (i = 0; i < strlen(key); i++) {
        if (key[i] == 'j') key[i] = 'i';
        if (!dict[key[i] - 'a'] && isalpha(key[i])) {
            dict[key[i] - 'a'] = 1;
            keyTable[k / SIZE][k % SIZE] = key[i];
            k++;
        }
    }

    for (i = 0; i < 26; i++) {
        if (i == ('j' - 'a')) continue;
        if (!dict[i]) {
            keyTable[k / SIZE][k % SIZE] = i + 'a';
            k++;
        }
    }
}

void search(char keyTable[SIZE][SIZE], char a, char b, int pos[]) {
    int i, j;
    if (a == 'j') a = 'i';
    if (b == 'j') b = 'i';
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (keyTable[i][j] == a) {
                pos[0] = i;
                pos[1] = j;
            }
            if (keyTable[i][j] == b) {
                pos[2] = i;
                pos[3] = j;
            }
        }
    }
}

void encrypt(char str[], char keyTable[SIZE][SIZE]) {
    int i, pos[4];
    for (i = 0; i < strlen(str); i += 2) {
        if (str[i] == str[i + 1]) str[i + 1] = 'x';
        search(keyTable, str[i], str[i + 1], pos);

        if (pos[0] == pos[2]) {
            printf("%c%c", keyTable[pos[0]][(pos[1] + 1) % SIZE], keyTable[pos[0]][(pos[3] + 1) % SIZE]);
        } else if (pos[1] == pos[3]) {
            printf("%c%c", keyTable[(pos[0] + 1) % SIZE][pos[1]], keyTable[(pos[2] + 1) % SIZE][pos[1]]);
        } else {
            printf("%c%c", keyTable[pos[0]][pos[3]], keyTable[pos[2]][pos[1]]);
        }
    }
    printf("\n");
}

int main() {
    char key[] = "keyword";
    char text[] = "helloworld";
    char keyTable[SIZE][SIZE];

    prepareKey(key, keyTable);
    printf("Encrypted text: ");
    encrypt(text, keyTable);

    return 0;
}

