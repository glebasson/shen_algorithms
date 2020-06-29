#include <stdio.h>

int stringStat(char const* string, size_t multiplier, int * count) {
    size_t len = 0;
    char const* c = NULL;
    for(c = string; *c++ != '\0';) {
        len++;
    }
    (*count)++;
    return len * multiplier;
}
