#include <stdio.h>


extern int *p;
// extern int p[];


int main()
{
    for (int i = 0; i < 100; ++i)
        printf("p[%d] = %d\n", i, p[i]);
    return 0;
}
