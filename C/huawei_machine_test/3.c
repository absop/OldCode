#include<stdio.h>

int main()
{
    long n;
    scanf("%ld", &n);

    for (int i = 2; i <= n; ++i) {
        while ((n % i) == 0) {
            printf("%d ", i);
            n /= i;
        }
    }

    return 0;
}
