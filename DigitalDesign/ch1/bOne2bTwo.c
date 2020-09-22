/***
 * Translate number from base 1 to binary,
 * then binary to base 2.
 */
#include <stdio.h>

#define BUF_SIZE 255

unsigned int bOne2dec(unsigned int base, char const input[]) {
    unsigned int out = 0U;
    for(int i=0; input[i]; ++i) {
        out = out * base + (input[i] - 0x30);
    }
    return out;
}

void dec2bTwo(unsigned int base, unsigned int input) {
    char ar[BUF_SIZE];
    unsigned int d = 0;
    while(input) {
        ar[d] = (input % base) > 9 ? (input % base) + 0x37 : (input % base) + 0x30;
        input /= base;
        ++d;
    }
    while(d) {
        printf("%c", ar[--d]);
    }
    printf("\n");
}

int main(int argc, char const argv[]) {
    char input[BUF_SIZE];
    unsigned int baseIn;
    unsigned int baseOut;
    scanf("%u", &baseIn);
    scanf("%u", &baseOut);
    scanf("%s", &input);
    dec2bTwo(baseOut, bOne2dec(baseIn, input));
    return(0);
}