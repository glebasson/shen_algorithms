#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 255


int main(int argc, char const* argv[]) {
    int fd = open("input.txt", O_RDONLY);
    if(fd == -1) {
        perror("open");
        return errno;
    }
    char buf[BUF_SIZE];
    ssize_t num_bytes = 1;
    while (num_bytes) {
        if (num_bytes == -1) {
            perror("read");
            return errno;
        }
        num_bytes = read(fd, buf, 255);
        if (write(STDOUT_FILENO, buf, num_bytes) == -1) {
            perror("write to stdout");
            break;
        }
    }
    if (close(fd) == -1) {
        perror("close");
        return errno;
    }
    return EXIT_SUCCESS;
}