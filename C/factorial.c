#include <stdio.h>

// 采用十亿进制，每个int表示存储9位十进制
#define scale 1000000000
#define print_limb(limb) printf("%09d", limb)

void print_factorial(const int N)
{
    int i, j, len;
    int fac[4000] = {0};
    long long carry, factor;
    j = len = 0; fac[0] = 1;

    for (factor = 2; factor <= N; ++factor) {
        for (carry = 0, i = j; i <= len; ++i) {
            carry += factor * fac[i];
            fac[i] = carry % scale;  // 取余数
            carry /= scale;          // 进位
        }
        if (fac[j] == 0) ++j;
        if (carry > 0) {
            fac[i] = carry;
            ++len;
        }
    }
    printf("%d", fac[len]);
    while (--len >= 0)print_limb(fac[len]);
    printf("\n");
}

int main()
{
    // for (int i = 0; i < 40; ++i)
        // print_factorial(i);
    print_factorial(10000);

    return 0;
}