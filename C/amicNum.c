#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct {
    int length;
    int (*pair)[2];
} Vector;

Vector *getAmicNum(int maxn)
{
    int *sum = calloc(maxn + 1, sizeof(int));

    for (int i = 1; i <= maxn; ++i) {
        int j = i << 1;

        while (j <= maxn) {
            sum[j] += i;
            j += i;
        }
    }

    Vector *vec = (Vector *)malloc(sizeof(Vector));
    vec->length = 0;
    vec->pair = malloc(1000 * sizeof(int[2]));

    for (int i = 1; i <= maxn; ++i)
        if (i < sum[i] && sum[i] <= maxn && sum[sum[i]] == i) {
            vec->pair[vec->length][0] = i;
            vec->pair[vec->length][1] = sum[i];
            ++vec->length;
        }

    vec->pair = realloc(vec->pair, vec->length * sizeof(vec->pair[0]));
    free(sum);
    return vec;
}


const int maxn = 5000000;

int main()
{
    Vector *vec = getAmicNum(maxn);

    for (int i = 0; i < vec->length; ++i)
        printf("%d\t%d\n", vec->pair[i][0], vec->pair[i][1]);

    printf("Found %d pair of amicnum within %d\n\n", vec->length, maxn);
    free(vec);

    return 0;
}
