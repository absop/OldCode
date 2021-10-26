#include <math.h>
#include <memory.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


#define MAXN 1000000

int main()
{
    bool *isprimes = (bool *)malloc(MAXN + 1);
    memset(isprimes, true, MAXN + 1);

    int i, j, delta;
    int nprimes = 1; // for number 2.
    int sqmax = sqrt(MAXN);
    for (i = 3; i <= sqmax; i += 2) {
        if (isprimes[i]) {
            ++nprimes;
            j = i * i;
            delta = i << 1;
            while (j <= MAXN) {
                isprimes[j] = false;
                j += delta;
            }
        }
    }
    for (; i <= MAXN; i += 2) {
        if (isprimes[i])
            ++nprimes;
    }

#define g(i, j) (j * (j + 1) + i)
    int k, all, cnt = 1, gcnt = 0;
    for (i = 3; i <= MAXN ; i += 2) {
        if (isprimes[i]) {
            all = true;
            for (j = 1; j < i - 1 && (k = g(i, j)) <= MAXN; ++j) {
                if (!isprimes[k]) {
                    all = false;
                    break;
                }
            }
            if (k > MAXN) break;
            if (all) {
                printf("%d\n", i);
                ++gcnt;
            }
            ++cnt;
        }
    }
    free(isprimes);

    printf("nprimes: %d\n", nprimes);
    printf("cnt: %d, gcnt: %d\n", cnt, gcnt);

    return 0;
}
