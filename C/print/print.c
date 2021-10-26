#include <stdio.h>
#include <string.h>

void print_digit(int n)
{
    putchar(n + '0');
}

void print_num(int n)
{
    if (n >= 10) {
        print_num(n / 10);
        putchar(' ');
    }
    print_digit(n % 10);
}

void print_array(int array[], int len)
{
    if (len > 1) {
        print_array(array, len - 1);
        putchar(' ');
    }
    print_num(array[len - 1]);
}


int main()
{
    return 0;
}
