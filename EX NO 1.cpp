#include <stdio.h>
#include <string.h>
#include <ctype.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - offset + shift) % 26 + offset;
        }
    }
}

void decrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; ++i) {
        char ch = text[i];

        if (isalpha(ch)) {
            char offset = isupper(ch) ? 'A' : 'a';
            text[i] = (ch - offset - shift + 26) % 26 + offset;
        }
    }
}

int main() {
    char text[100];
    int shift, choice;

    printf("Enter the text: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // Remove newline

    printf("Enter shift value: ");
    scanf("%d", &shift);

    printf("Choose an option:\n1. Encrypt\n2. Decrypt\n");
    scanf("%d", &choice);

    if (choice == 1) {
        encrypt(text, shift);
        printf("Encrypted text: %s\n", text);
    } else if (choice == 2) {
        decrypt(text, shift);
        printf("Decrypted text: %s\n", text);
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}

