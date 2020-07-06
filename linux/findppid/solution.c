#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 255

int main() {
    char path[BUF_SIZE];
    sprintf(path, "/proc/%d/stat", getpid());
    FILE * f = fopen(path, "r");
    if (f == NULL) {
        perror("open");
        return EXIT_FAILURE;
    }
    char str[BUF_SIZE];
    if (fgets(str, BUF_SIZE, f) == NULL) {
        perror("gets");
        return EXIT_FAILURE;
    }
    char * p = strtok(str, " ");
    int i;
    for (i = 0; i < 2; i++) {
        p = strtok(NULL, " "); 
    }
    p = strtok(NULL, " ");
    printf("%s\n", p);
    fclose(f);
}