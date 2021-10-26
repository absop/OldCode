#include <stdio.h>
#include <time.h>

#ifndef __TINYC__
    #define offsetof(type, field) ((size_t) &((type *)0)->field)
#endif

#define cat(x, y) x ## y
#define cat(x, y) x ## y
// #define cat(a, b) a ## b
#undef xcat
#undef xcat(x, y)
#undef xcat(x, y) cat(x, y)
#define xcat(x, y) cat(x, y)

struct FuncAttr {
    unsigned
    func_call     : 3, /* calling convention (0..5), see below */
                  func_type     : 2, /* FUNC_OLD/NEW/ELLIPSIS */
                  func_noreturn : 1, /* attribute((noreturn)) */
                  xxxx          : 2,
                  func_args     : 8; /* PE __stdcall args */
};

typedef struct _node {
    int size;
    void *data;
} Node;

void sum(int *to, int *from, int count)
{
    int n = count / 8;
    switch (count % 8) {
        case 0:
            while (n -- > 0) {
                *to += *from++;
            case 7: *to += *from++;
            case 6: *to += *from++;
            case 5: *to += *from++;
            case 4: *to += *from++;
            case 3: *to += *from++;
            case 2: *to += *from++;
            case 1: *to += *from++;
            }
    }
}

long long accumulate(int begin, int end)
{
    long long total = 0;
    int count = end - begin;
    int loop = count / 8;
    switch (count % 8) {
        case 0:
            while (loop --> 0) {
                total += begin++;
            case 7: total += begin++;
            case 6: total += begin++;
            case 5: total += begin++;
            case 4: total += begin++;
            case 3: total += begin++;
            case 2: total += begin++;
            case 1: total += begin++;
            }
    }
    return total;
}

int main()
{
    // printf("%d\n", cat(cat(123, 456), 789));
    printf("%d\n", xcat(xcat(123, 456), 789));
    // int maxn;
    // clock_t begin, end;
    // scanf("%d", &maxn);
    // begin = clock();
    // long long total = accumulate(0, maxn);
    // end = clock();
    // printf("total:%lld, time:%d\n", total, end - begin);

    // printf("%d\n", sizeof(struct FuncAttr));
    // printf("%d\n", offsetof(struct FuncAttr, func_call));
    // printf("%d\n", offsetof(struct FuncAttr, func_args));

    // Node node = {1, (void *)128}, *p = &node;
    // printf("%p\n", p);
    // printf("%p\n", (char *)p);

    // int a[101];
    // for (int i = 0; i <= 100; ++i)
    //     a[i] = i;
    // sum(a, a + 1, 100);

    // printf("%d\n", 0[a]);
}
