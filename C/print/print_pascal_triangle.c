#include <stdio.h>
#include <string.h>

#define maxrow 32
#define maxlen 256
void print_pascal_triangle(int n)
{
    if (n > maxrow)return;

    char lines[maxrow][maxlen];
    int num[2][maxrow] = {0};
    int len[maxrow], align[maxrow];
    num[0][0] = num[1][0] = 1;

    /* Calculate and write to a array */
    for (int i = 0; i < n; ++i) {
        int k = i & 0x1;
        char *ptr = lines[i];
        for (int j = 0;  j < i; ++j) {
            num[k][j + 1] = num[!k][j + 1] + num[!k][j];
            ptr += sprintf(ptr , "%d ", num[k][j]);
        }
        ptr += sprintf(ptr , "%d\n", num[k][i]);
        *ptr = 0;
    }

    /* Centered align print */
    int longest = 0;
    for (int i = 0; i < n; ++i) {
        len[i] = strlen(lines[i]);
        if (len[i] > longest)
            longest = len[i];
    }

    for (int i = 0; i < n; ++i)
        align[i] = (longest - len[i]) / 2;

    for (int i = 0; i < n - 1; ++i)
        printf("%*c%s", align[i], ' ', lines[i]);
    printf("%s", lines[n - 1]);
}


int main()
{
    int degree = 25;
    printf("\n\nÑî»ÔÈý½Ç£º %d\n", degree);
    print_pascal_triangle(degree);
    return 0;
}
