#include <stdio.h>


int gcd(int p, int q)
{ return q ? gcd(q, p % q) : p; }


int main()
{
    char digits[16];
    int integer, g;
    int deno = 1, memb = 0, i = 0;

    scanf("%d.%s", &integer, digits);

    while (digits[i] == '0') {
        deno *= 10;
        i++;
    }
    while (digits[i] != 0) {
        memb *= 10;
        deno *= 10;
        memb += digits[i++] - '0';
    }

    g = gcd(memb, deno);
    memb /= g;
    deno /= g;

    printf("%d+%d/%d\n", integer, memb, deno);
}