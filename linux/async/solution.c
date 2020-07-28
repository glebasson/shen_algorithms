#include <stdio.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>

int count = 0;
int isopen = 2;

void sum(int fd) {
    char buff[100];

    int bytes = read(fd, buff, 100);
    if (bytes == 0) {
        isopen--;
    }
    buff[bytes] = 0;
    int i;
    sscanf(buff, "%d", &i);
    count += i;
}

int main() {
    int f1 = open("./in1", O_RDWR);
    int f2 = open("./in2", O_RDWR);
    if(f1 == -1 || f2 == -1) {
        printf("Errors with pipe opening!\n");
    }

    fd_set read_set;
    while(isopen) {
        FD_ZERO(&read_set);
        FD_SET(f1, &read_set);
        FD_SET(f2, &read_set);
        int result = select(f2+1, &read_set, NULL, NULL, NULL);
        if(result) {
            if( FD_ISSET(f1, &read_set) )
                sum(f1);
            if( FD_ISSET(f2, &read_set) )
                sum(f2);
        }
    }
    printf("%d", count);
}