#include <stdio.h>
#include <string.h>

void print_99(void)
{
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j < i; ++j)
            printf("%d��%d=%d\t", j, i, i * j);
        printf("%d��%d=%d\n", i, i, i * i);
    }
}

int main()
{
    printf("\n\n�žų˷���\n");
    print_99();
    return 0;
}
