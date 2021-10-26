#include<time.h>
#include<math.h>
#include<iostream>
#include<gmpxx.h>

using namespace std;

typedef mpz_class Bignum;

Bignum squa(Bignum x)
{
	return x * x;
}

Bignum fibo(int n)
{
	if (n < 2) return n;

	Bignum fibc;
	Bignum fib0 = 0;
	Bignum fib1 = 1;

	for (int i = (int)log2(n) - 1; i >= 0; --i) {
		fibc = fib1;
		if ((n >> i) & 0x1) {
			fib1 = squa(fib1) + squa(fib1 + fib0);
			if (!i)return fib1;
			fib0 = fibc * (fibc + 2 * fib0);
		}
		else {
			fib1 = fib1 * (fib1 + 2 * fib0);
			if (!i)return fib1;
			fib0 = squa(fib0)  +  squa(fibc);
		}
	}
}

void print(Bignum num)
{
	gmp_printf("%Zd\n", num.get_mpz_t ());
}

int main(int argc, char const *argv[])
{
#if 0
	for (int i = 0; i < 101; ++i)
		print(fibo(i));
#endif

#if 1
	int len, number = 100000000;
	Bignum z;
	clock_t start, finish;
	bool PRINT = false;
	if (--argc) {
		PRINT = true;
		number = 0;
		for (int i = 0; argv[1][i]; ++i)
			number = number * 10 + argv[1][i] - '0';
	}
	start = clock();
	z = fibo(number);
	finish = clock() - start;
	if (PRINT) {
		printf("fibo(%d) = ", number);
		print(z);
	}
	len = mpz_sizeinbase(z.get_mpz_t(), 10);
	printf("length_of_fibo(%d) = %d\n", number, len);
	printf("Calculate this number totally casted time %ld us\n\n", finish);
#endif

	return 0;
}