#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>

#define BUF_SIZE 1023

int main() {
    DIR * dir = opendir("/proc");
    if (dir == NULL) {
        perror("opendir");
        return EXIT_FAILURE;
    }
    struct dirent * entry;
    char str[BUF_SIZE] = "";
    size_t count = 0;
    while ((entry = readdir(dir)) != NULL) {
        if (entry->d_type != DT_DIR) {
            continue;
        }
        sprintf(str, "/proc/%s/stat", entry->d_name);
        FILE * f = fopen(str, "r");
        if (f) {
            fscanf(f, "%*s %s", str);
            if (strstr(str, "genenv")) {
                count++;
            }
            fclose(f);
        }
    }
    if(closedir(dir) < 0) {
        perror("closedir");
        return EXIT_FAILURE;
    }
    printf("%zu\n", count);
}