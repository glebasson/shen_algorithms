#include <stdio.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <dlfcn.h>

int (*secretFunction)(int);

int main(int argc, char * argv[]) {
    void * hdl = dlopen(argv[1], RTLD_LAZY);
    secretFunction = (int (*)(int))dlsym(hdl, argv[2]);
    printf("%d\n", secretFunction(atoi(argv[3])));
    return 0;
}
