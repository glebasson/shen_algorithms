#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define BUF_SIZE 255

char str[BUF_SIZE] = "";

int count = 0;

void countPsTree(pid_t pid) {
    pid_t ppid;
    pid_t cpid;
    count++;
    DIR * dir = opendir("/proc");
    if (!dir) {
        perror("diropen()");
        return;
    }
    struct dirent * de;
    de = readdir(dir);
    while(de = readdir(dir)) {
        if(de->d_type == DT_DIR) {
            sprintf(str, "/proc/%s/stat", de->d_name);
            FILE * f = fopen(str, "r");
            if (!f) {
                continue;
            }
            fscanf(f, "%d %*s %*s %d", &cpid, &ppid);
            fclose(f);
            if (ppid == pid) {
                countPsTree(cpid);
            }
        }
    }
    closedir(dir);
}

int main(int argc, char const* argv[]) {
    pid_t ipid;
    sscanf(argv[1], "%d", &ipid);
    countPsTree(ipid);
    printf("%d\n", count);
    return EXIT_SUCCESS;
}