#include<stdio.h>
#include<stdlib.h>
#include<memory.h>


// 在线面试平台。将链接分享给你的朋友以加入相同的房间。
// Author: tdzl2003<dengyun@meideng.net>

// Given float array A, int k, 求 float arry B,
// B[i] = average(A[i-k], A[i-k+1], ..., A[i+k]), len(A) == len(B)
// Example:
// A = [1,2,3,4,5], k=1, B = [1.5, 2, 3, 4, 4.5]


float *solve(float A[], int len, int k)
{
    double sum = 0;
    float *B = (float *)malloc(sizeof(*A) * len);
    int n;
    for (n = 0; n < k && n < len ; ++n)
        sum += A[n];
    for (int i = 0; i < len; ++i) {
        if (i + k < len) {
            sum += A[i + k];
            n += 1;
        }
        B[i] = sum / n;
        if (i - k >= 0) {
            sum -= A[i - k];
            n -= 1;
        }
    }

    return B;
}

int main()
{
    float A[] = {1, 2, 3, 4, 5};
    float *B = solve(A, sizeof(A) / sizeof(A[0]), 1);
    for (int i = 0; i < sizeof(A) / sizeof(A[0]); ++i)
        printf("%g\n", B[i]);
    free(B);

    return 0;
}
