#!/usr/bin/tcc -run -lgmp

#include<time.h>
#include<math.h>
#include<gmp.h>
#include<stdio.h>


void fib(mpz_t fibc, int n)
{

    mpz_t fib0, fib1;
    mpz_t fib02, fib12, fibc2;
    mpz_init(fib0);
    mpz_init(fib1);
    mpz_init(fibc);
    mpz_init(fib02);
    mpz_init(fib12);
    mpz_init(fibc2);
    mpz_set_ui(fib0, 0);
    mpz_set_ui(fib1, 1);
    mpz_set_ui(fibc, n & 0x1);

    int i = 0;
    while ((n >> i) > 1)++i;
    for (i -= 1; i >= 0; --i) {
        if ((n >> i) & 0x1) {
            mpz_add(fib02, fib0, fib1);
            mpz_mul(fib12, fib1, fib1);
            mpz_mul(fibc2, fib02, fib02);
            mpz_add(fibc, fibc2, fib12);
            if (!i)break;
            mpz_add(fib12, fib02, fib0);
            mpz_mul(fib0, fib1, fib12);
        }
        else {
            mpz_add(fib02, fib0, fib0);
            mpz_add(fib12, fib1, fib02);
            mpz_mul(fibc, fib1, fib12);
            if (!i)break;
            mpz_mul(fib02, fib0, fib0);
            mpz_mul(fib12, fib1, fib1);
            mpz_add(fib0, fib02, fib12);
        }
        mpz_set(fib1, fibc);
    }
    mpz_clear(fib0);
    mpz_clear(fib1);
    mpz_clear(fib02);
    mpz_clear(fib12);
    mpz_clear(fibc2);
}


int main(int argc, char const *argv[])
{
#if 1
    mpz_t fibc;
    for (int i = 0; i < 101; ++i) {
        fib(fibc, i);
        printf("fib(%3d):\t", i);
        gmp_printf("%Zd\n", fibc);
    }
    mpz_clear(fibc);
#endif

    mpz_t fibn;
    int len, num = 100000000;
    if (argc == 2 && isdigit(argv[1][0])) {
        num = (argv[1][0] - '0');
        for (int i = 1; isdigit(argv[1][i]); ++i) {
            num *= 10;
            num += (argv[1][i] - '0');
        }
    }
    clock_t start, finish;
    start = clock();
    fib(fibn, num);
    len = mpz_sizeinbase(fibn, 10);
    mpz_clear(fibn);
    finish = clock() - start;
    printf("length of fib(%d): %d\n", num, len);
    printf("time: %ld us\n\n", finish);
    return 0;
}