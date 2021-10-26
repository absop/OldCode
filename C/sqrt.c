#include <stdio.h>


float fsqrt( float x)
{
    float x2 = 0.5F * x;
    long i = * ( long * ) & x; // evil floating point bit level hacking

    i = 0x5f3759df - ( i >> 1 );
    x = * ( float * ) &i;
    x *= ( 1.5F - ( x2 * x * x ) ); // 1st iteration
    x *= ( 1.5F - ( x2 * x * x ) ); // 2nd iteration

    return 1 / x;
}

int isqrt (int x) { return (int)fsqrt(x);}


int main(int argc, char const *argv[])
{
    int n = 1000000000;
    printf("isqrt(%d)=%d\n", n, isqrt(n));
    printf("fsqrt(%d)=%f\n", n, fsqrt(n));
    return 0;
}
