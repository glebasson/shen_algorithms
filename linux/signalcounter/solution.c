#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int sig1=0;
void usr1_handler(int signalno) {
    sig1++;
}

int sig2=0;
void usr2_handler(int signalno) {
    sig2++;
}

void term_handler(int signalno) {
    printf("%d %d\n", sig1, sig2);
    exit(0);
}

int main(int argc, char const* argv[]) {
    signal(SIGUSR1, usr1_handler);
    signal(SIGUSR2, usr2_handler);
    signal(SIGTERM, term_handler);
    for(;;){}
}