#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const* argv[]) {
    char buf[255];
    sprintf(buf, "%s %s", argv[1], argv[2]);
    FILE * pipe = popen(buf, "r");
    if (pipe <= 0) {
        perror("popen");
        return EXIT_FAILURE;
    }
    int zc=0;
    char c;
    while((c = fgetc(pipe)) > 0) {
        if (c == '0') {
            zc++;
        }
    }
    printf("%d\n", zc);
    if (pclose(pipe) < 0) {
        perror("pclose");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;

}