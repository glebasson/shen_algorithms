#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


#define BUFSIZE 5120

struct sockaddr_in local;

int comparison(const void* a, const void* b) {
    char f = *((char*)a);
    char s = *((char*)b);
    if (f < s) return 1;
    if (f > s) return -1;
    return 0;
}

int main(int c, char **v) {
    int s = socket(AF_INET, SOCK_STREAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(v[1]));
    local.sin_family = AF_INET;
    bind(s, (struct sockaddr*) &local, sizeof(local));
    listen(s, 5);
    int cs;
    cs = accept(s, NULL, NULL);
    char buf[5120];
    int num;
    while(num = read(cs, buf, BUFSIZE)) {
        if (strncmp(buf, "OFF", 3) == 0) {
            break;
        }
        qsort(buf, num-1, sizeof(char), comparison);
        write(cs, buf, num);
    }
    close(cs);
    return EXIT_SUCCESS;
}