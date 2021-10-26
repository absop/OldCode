#include <stdio.h>
#include <time.h>


int main()
{
    clock_t start = clock();
    long long sum = 0, i = 1;
    while(i <= 100000000){
        sum += i;
        i++;
    }
    clock_t cost = clock() - start;
    printf("sum = %lld\n", sum);
    printf("cost %d ms\n", cost);
    return 0;
}
