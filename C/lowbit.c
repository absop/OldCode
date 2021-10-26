#include <stdio.h>
#include <stdlib.h>

#define lowbit(i) ((i) & (-(i)))


int main()
{
    printf("%d\n", lowbit(9));  // 1
    printf("%d\n", lowbit(10)); // 2
    printf("%d\n", lowbit(11)); // 1
    printf("%d\n", lowbit(12)); // 4
    return 0;
}
