#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int chr;
    int num;
} alpha_T;

static inline void Swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void AlphaSort(alpha_T alpha[], int len)
{
    for (int i = 0; i < len - 1; ++i) {
        for (int j = i; j < len; ++j) {
            if (alpha[i].num < alpha[j].num) {
                Swap(&alpha[i].chr, &alpha[j].chr);
                Swap(&alpha[i].num, &alpha[j].num);
            }
        }
    }
}

int main()
{
    alpha_T lower[26] = {0};
    FILE *fp = fopen("amicNum.c", "r");
    if (!fp) {
        fprintf(stderr, "No such file or directory!\n");
        exit(0);
    }

    for (int i = 0; i < 26; ++i)
        lower[i].chr = i + 'a';

    char c;
    for (; (c = fgetc(fp)) != EOF;)
        if ('a' <= c && c <= 'z')
            lower[c - 'a'].num += 1;

    AlphaSort(lower, 26);

    int total = 0;
    for (int i = 0; i < 10; ++i) {
        if (lower[i].num > 0) {
            printf("%c: %d\n", lower[i].chr, lower[i].num);
            total += lower[i].num;
        }
    }
    printf("Total: %d\n", total);

    fclose(fp);
    return 0;
}
