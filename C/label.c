#include <stdio.h>

void *global_lable;

void test()
{
    __label__ label;
    global_lable = &&label;
    printf("test is running\n");

label:
    printf("test is finished\n");
}

int main()
{
    test();
    goto *global_lable;

    printf("main");
    return 0;
}
