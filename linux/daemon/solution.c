#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>
#include <signal.h>

void usr1_handler(int signalno) {
    exit(0);
}

int main(int argc, char const* argv[]) {
    printf("%d\n", getpid());
    pid_t pid = fork();
    if (pid == 0) {
        signal(SIGURG, usr1_handler);
        setsid();
        fsync(STDOUT_FILENO);
        close(STDERR_FILENO);
        close(STDIN_FILENO);
        close(STDOUT_FILENO);
        while(1) {}
    }
    return EXIT_SUCCESS;
}