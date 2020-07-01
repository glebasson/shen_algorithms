#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stddef.h>


int main(int argc, char const* argv[]) {
    DIR * dir = opendir("./");
    if (dir == NULL) {
        perror("opendir");
        return errno;
    }
    struct dirent * entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }
    if(closedir(dir) < 0) {
        perror("closedir");
        return errno;
    }
}