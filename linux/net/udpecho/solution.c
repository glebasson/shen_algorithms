#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>


#define BUFSIZE 5120

struct sockaddr_in local;

int main(int c, char **v) {
    int s = socket(AF_INET, SOCK_DGRAM, 0);

    inet_aton("127.0.0.1", &local.sin_addr);
    local.sin_port = htons(atoi(v[1]));
    local.sin_family = AF_INET;
    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    char buf[5120];
    int num;
    while(num = read(s, buf, BUFSIZE)) {
        if (strncmp(buf, "OFF\n", 4) == 0) {
            break;
        }
        buf[num] = '\0';
        printf("%s\n", buf);
    }
    return EXIT_SUCCESS;
}