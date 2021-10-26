#include <stdio.h>
#include <string.h>

int is_huiwen(int n)
{
    int len, digit[12];
    for (len = 0; n; ++len) {
        digit[len] = n % 10;
        n /= 10;
    }
    for (int i = 0; i <= len / 2; ++i)
        if (digit[i] != digit[len - i - 1])
            return 0;
    return 1;
}

// Find palindromic number between min and max,
// print n number per line
int print_huiwen_num(int min, int max, int n)
{
    int cnt = 0;
    for (int i = min; i <= max; ++i)
        if (is_huiwen(i)) {
            ++ cnt;
            if (cnt % n)
                printf("%d\t", i);
            else printf("%d\n", i);
        }
    printf("\n");
    return cnt;
}


int main()
{
    int min = 0, max = 1000000, degree = 25;
    printf("回文数：\n");
    printf("%d~%d内有%d个回文数\n", min, max, print_huiwen_num(min, max, 10));
    return 0;
}
