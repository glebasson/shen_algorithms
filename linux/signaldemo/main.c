#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void mysignal_handler(int signalno) {
    printf("Called with %d\n", signalno);
}

int main() {
    int c=0;
    signal(SIGINT, mysignal_handler);
    for(;;) {
        printf("Hi %d\n", c++);
        usleep(50000);
    }
    return EXIT_SUCCESS;
}