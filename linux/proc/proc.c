#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char const* argv[]) {
    pid_t pid = fork();
    if (pid == 0) {
        printf("I am a child proc!\n");
    } else {
        printf("And I am is parrnet\n");
    }
    return(0);
}