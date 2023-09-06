#include <stdio.h>
#include <string.h>
#include <openssl/md5.h>

int main() {
    char input[] = "Hello, MD5!";
    unsigned char digest[MD5_DIGEST_LENGTH]; // 16 bytes

    MD5((unsigned char*)&input, strlen(input), digest);

    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
