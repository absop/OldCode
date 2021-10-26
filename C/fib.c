#!/usr/bin/tcc -run

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define log2(x) (log(x)/log(2))

static inline long long
sumSquare(long long n, long long m)
{
    return n * n + m * m;
}

long long fib(int n)
{
    long long fibr = n & 0x1;
    long long fib0 = 0, fib1 = 1;

    int i = 0;
    while ((n >> i) > 1)++i;
    for (i -= 1; i >= 0; --i) {
        if ((n >> i) & 0x1) {
            fibr = sumSquare(fib1, fib1 + fib0);
            if (!i)break;
            fib0 = fib1 * (fib1 + (fib0 << 1));
        }
        else {
            fibr = fib1 * (fib1 + (fib0 << 1));
            if (!i)break;
            fib0 = sumSquare(fib0, fib1);
        }
        fib1 = fibr;
    }
    return fibr;
}

int main()
{
    for (int i = 0; i < 90; ++i)
        printf("%d: %lld\n", i, fib(i));

    return 0;
}