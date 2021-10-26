#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void lcs_dp(char *s1, char *s2)
{
    int l1 = strlen(s1), l2 = strlen(s2), maxl = 0;
    int dp_l1 = (l1 + 1), dp_l2 = (l2 + 1);
    int *dp = (int *)calloc(dp_l1 * dp_l2, sizeof (int));
    int sub1 = -1, sub2 = -1;

#define dp(i, j) dp[(i) * dp_l2 + j]
#define prints(n) \
    printf("%s\n", s##n);\
    for (int i = 0; i < sub##n + maxl; ++i)\
        putchar(sub##n <= i ? '^' : ' ');\
    putchar('\n');

    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j) {
            if (s1[i - 1] == s2[j - 1]) {
                dp(i, j) = dp(i - 1, j - 1) + 1;
                if (maxl < dp(i, j)) {
                    maxl = dp(i, j);
                    sub1 = i - maxl;
                    sub2 = j - maxl;
                }
            }
        }
    }
#if 0
    for (int i = 1; i <= l1; ++i) {
        for (int j = 1; j <= l2; ++j)
            printf("%3d%c", dp(i, j), (j == l2) ? '\n' : ' ');
    }
#endif
    if (maxl > 0) {
        prints(1)
        prints(2)
        printf("(%d, %d)[%d]\n", sub1, sub2, maxl);
        for (int i = sub1; i < sub1 + maxl; ++i)
            putchar(s1[i]);
        putchar('\n');
    }

    free(dp);
}


int main()
{
    lcs_dp("1234567890", "abcdefghijk12306");
    printf("\n");
    lcs_dp("1234567890", "7890123456");

    return 0;
}
