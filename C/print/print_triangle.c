#include <stdio.h>

int print(int n)
{
    int l, r;
    for (int i = 0; i < n; ++i) {
        r = n + i;
        l = n - i;
        for (int j = 1; j <= r; ++j)
            putchar(j > l && j < r ? '#' :
                    j == r || j == l ? 'A' :
                    ' ');
        printf("\n");
    }
}

int main()
{
    print(10);
    return 0;
}