#include <stdio.h>
#define N 3

int main()
{
    int n, i, j;
    printf("�������:");
    scanf("%d", &n);

    int arr[n][n];
    for (i = 0; i < n; i++) { //��
        for (j = 0; j <= i; j++) { //��
            if (j == 0 || j == i)
                arr[i][j] = 1;
            else
                arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
            printf("%*d", j == 0 ? (n - i)*N : 2 * N, arr[i][j]);
        }
        putchar(10);
    }
    return 0;
}//�޸�N��ֵ,����б��,�������̫�����ּ�һ��
