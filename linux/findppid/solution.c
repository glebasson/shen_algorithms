#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 255

pid_t findPPid(pid_t pid) {
    char str[BUF_SIZE];
    sprintf(str, "/proc/%d/stat", pid);
    FILE * f = fopen(str, "r");
    if (f == NULL) {
        perror("open");
        return EXIT_FAILURE;
    }
    if (fscanf(f, "%*s %*s %*s %i", &pid) == EOF) {
        perror("scanf");
        return EXIT_FAILURE;
    }
    if (fclose(f) == EOF) {
        perror("close");
        return EXIT_FAILURE;
    }
    return pid;
}

void printPidTree(pid_t pid) {
    printf("%d\n", pid);
    pid_t ppid = findPPid(pid);
    if (ppid) {
        printPidTree(ppid);
    }
}

int main(int argc, char const* argv[]) {
    pid_t pid;
    sscanf(argv[1], "%i", &pid);
    printPidTree(pid);
    return EXIT_SUCCESS;
}