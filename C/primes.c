#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct Vector {
    int *number;
    int length;
} Vector;


// gcc对这个函数开启 -O1 优化效果非常好
Vector get_primes(int maxn)
{
    int i, j, k, cnt = 0;
    int *primes = (int *)malloc(sizeof(int) * maxn / 2);
    char *isPrime = (char *)malloc(maxn + 1);
    memset(isPrime, 1, maxn + 1);
    primes[cnt++] = 2;

    for (i = 3; i <= maxn; i += 2) {
        if (isPrime[i])
            primes[cnt++] = i;
        k = 3 * i;
        for (j = 1; k <= maxn;) {
            isPrime[k] = 0;
            if (i % primes[j] == 0 || ++j > cnt) break;
            k = i * primes[j];
        }
    }

    free(isPrime);
    Vector p;
    p.length = cnt;
    p.number = realloc(primes, cnt * sizeof(int));
    return p;
}


int main()
{
    clock_t st, et;

    st = clock();
    Vector p = get_primes(100000000);
    et = clock() - st;

    printf("%d\n", p.length);
    printf("Elapsed time : %ld ms\n\n", et);

    free(p.number);
    return 0;
}
