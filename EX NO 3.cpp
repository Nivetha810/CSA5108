#include <stdio.h>
#include <string.h>

void getKeyMatrix(char key[], int keyMatrix[2][2]) {
    int k = 0;
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            keyMatrix[i][j] = (key[k++] - 'A') % 26;
}

void encrypt(char message[], int keyMatrix[2][2], int cipherMatrix[]) {
    for (int i = 0; i < 2; i++) {
        cipherMatrix[i] = 0;
        for (int j = 0; j < 2; j++)
            cipherMatrix[i] += keyMatrix[i][j] * (message[j] - 'A');
        cipherMatrix[i] %= 26;
    }
}

void HillCipher(char message[], char key[]) {
    int keyMatrix[2][2], cipherMatrix[2];
    getKeyMatrix(key, keyMatrix);

    printf("Encrypted text: ");
    for (int i = 0; i < strlen(message); i += 2) {
        char m[2] = { message[i], message[i + 1] ? message[i + 1] : 'X' };
        encrypt(m, keyMatrix, cipherMatrix);
        for (int j = 0; j < 2; j++)
            printf("%c", cipherMatrix[j] + 'A');
    }
    printf("\n");
}

int main() {
    char message[] = "HELP";
    char key[] = "GYBN";  // Example key: |6 24| |1 13|

    HillCipher(message, key);
    return 0;
}

