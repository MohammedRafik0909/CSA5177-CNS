#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Function to encrypt the plaintext using Vigenere Cipher
void vigenereEncrypt(char *plaintext, char *key) {
    int i, j;
    int plaintextLen = strlen(plaintext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < plaintextLen; ++i) {
        if (isalpha(plaintext[i])) {
            char shift = islower(plaintext[i]) ? 'a' : 'A';
            plaintext[i] = (plaintext[i] + key[j] - 2 * shift) % 26 + shift;
            j = (j + 1) % keyLen;
        }
    }
}

// Function to decrypt the ciphertext using Vigenere Cipher
void vigenereDecrypt(char *ciphertext, char *key) {
    int i, j;
    int ciphertextLen = strlen(ciphertext);
    int keyLen = strlen(key);

    for (i = 0, j = 0; i < ciphertextLen; ++i) {
        if (isalpha(ciphertext[i])) {
            char shift = islower(ciphertext[i]) ? 'a' : 'A';
            int diff = (ciphertext[i] - key[j] + 26) % 26;
            ciphertext[i] = diff + shift;
            j = (j + 1) % keyLen;
        }
    }
}

int main() {
    char plaintext[100], key[100], ciphertext[100];

    printf("Enter the plaintext: ");
    fgets(plaintext, sizeof(plaintext), stdin);
    printf("Enter the key: ");
    fgets(key, sizeof(key), stdin);

    // Remove newline characters from input
    strtok(plaintext, "\n");
    strtok(key, "\n");

    vigenereEncrypt(plaintext, key);
    printf("Encrypted Text: %s\n", plaintext);

    vigenereDecrypt(plaintext, key);
    printf("Decrypted Text: %s\n", plaintext);

    return 0;
}
