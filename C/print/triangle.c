#include <stdio.h>
#define N 3

int main()
{
    int n, i, j;
    printf("输入阶数:");
    scanf("%d", &n);

    int arr[n][n];
    for (i = 0; i < n; i++) { //行
        for (j = 0; j <= i; j++) { //列
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%*d", j == 0 ? (n - i)*N : 2 * N, arr[i][j]);
        }
        putchar(10);
    }
    return 0;
}//修改N的值,增加斜率,避免层数太大数字挤一起
