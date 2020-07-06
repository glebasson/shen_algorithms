#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 255

void runProgram(char * buf){
    char const* args[BUF_SIZE];
    char * b = strtok(buf, " \n");
    args[0] = buf;
    int argcount = 0;
    while (b) {
        b = strtok(NULL, " \n");
        args[++argcount] = b; 
    }
    args[argcount + 1] = NULL;
    execv(args[0], (char * const*)args);
}


int main(int argc, char const* argv[]) {
    char buf[BUF_SIZE] = "";
    int status;
    while(fgets(buf, BUF_SIZE, stdin)) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            return EXIT_FAILURE;
        }
        if(pid == 0) {
            runProgram(buf);
        } else {
            wait(&status);
        }
    }
}