#include <stdio.h>

int main(int argc, char const argv[]) {
    char input[255];
    scanf("%s", &input);
    unsigned int out = 0U;
    for(int i=0; input[i]; ++i) {
        out = out * 2 + (input[i] - 0x30);
    }
    printf("%u\n", out);
    return(0);
}