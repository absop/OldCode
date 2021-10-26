#include<stdio.h>

enum { A, B, C, D, E, ERR, PRI };

#define TOINT(h1, h2, h3, h4) ((h1 << 24) + (h2 << 16) + (h3 << 8) + h4)
#define isA(h1, h2, h3, h4) (  1 <= (h1) && (h1) <= 126)
#define isB(h1, h2, h3, h4) (128 <= (h1) && (h1) <= 191)
#define isC(h1, h2, h3, h4) (192 <= (h1) && (h1) <= 223)
#define isD(h1, h2, h3, h4) (224 <= (h1) && (h1) <= 239)
#define isE(h1, h2, h3, h4) (240 <= (h1) && (h1) <= 255)
#define isP(h1, h2, h3, h4) (\
    ((h1) == 10) || \
    ((h1) == 172 && (16 <= (h2) && (h2) <= 31)) || \
    ((h1) == 192 && (h2) == 168)\
)
/*
#define isP(h1, h2, h3, h4) ({int host = TOINT(h1, h2, h3, h4); \
    (\
     (TOINT( 10,   0, 0, 0) <= host && host <= TOINT( 10, 255, 255, 255)) || \
     (TOINT(172,  16, 0, 0) <= host && host <= TOINT(172,  31, 255, 255)) || \
     (TOINT(192, 168, 0, 0) <= host && host <= TOINT(192, 168, 255, 255)) || \
    0);\
})
*/

int ismask(int mask)
{
    if (mask == 0 || mask == TOINT(255, 255, 255, 255))
        return 0;

    int n = 0;
    while ((((mask >> n) & 0x1) == 0) && (n < 31)) {
        n += 1;
    }
    while ((((mask >> n) & 0x1) == 1) && (n < 31)) {
        n += 1;
    }
    return n == 31;
}

int main()
{
    int count[7] = {0};
    int h1, h2, h3, h4;
    int m1, m2, m3, m4;
    int ret;
    char line[64];

#define FMT "%d.%d.%d.%d~%d.%d.%d.%d"

    for (;(ret = scanf(FMT, &h1, &h2, &h3, &h4, &m1, &m2, &m3, &m4)) != EOF;) {
        if (ret != 8) {
            count[ERR] += 1;
            gets(line);
            continue;
        }
        // printf("output: ");
        // printf(FMT, h1, h2, h3, h4, m1, m2, m3, m4);
        // printf("\n");
        // if (h1 == 0 || h1 == 127)
        //     continue;
        if (!ismask(TOINT(m1, m2, m3, m4))) {
            count[ERR] += 1;
            continue;
        }

#define CASE(X) if (is##X(h1, h2, h3, h4)) {\
            count[X] += 1;\
            goto count_private;\
        }
        CASE(A)
        CASE(B)
        CASE(C)
        CASE(D)
        CASE(E)

       count_private:
        if (isP(h1, h2, h3, h4))
            count[PRI] += 1;
    }

    for (int i = 0; i < 7; ++i)
        printf("%d%c", count[i], i < PRI? ' ' : '\n');

    return 0;
}
