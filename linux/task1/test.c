#include "solution.h"
#include "stdio.h"
#include <assert.h>

int main(int argc, char const* argv[]) {
    int a = 5;
    int len = StringStat("Any string", 10, &a);
    assert(len == 100);
    assert(a == 6);
    printf("%d\n", len);
    return(0);
}