#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define maxn 100010
#define lowbit(x) ((x)&(-x))
/*
    树状数组应用于求前i个元素的和，并且适用于动态更新
    查询和更新的时间复杂度均为O(logn)

    本例是求数组中每个元素的左边比他小的元素个数
    如{1,5,3,2,6}，元素个数{0,1,1,1,4}

    使用hash存储每个数的个数，对于5来说，只要求
    hash[1] + hash[2] + ... + hash[4]的和，
    求和使用树状数组
*/
int c[maxn];

void update(int x, int v)
{
    // 覆盖x的树状数组加上v
    for (int i = x; i <= maxn; i += lowbit(i))
        c[i] += v;
}

int getSum(int x)
{
    // 获取前x的序列和
    // 树状数组从1开始
    int sum = 0;
    for (int i = x; i > 0; i -= lowbit(i))
        sum += c[i];
    return sum;
}

int binarySearch(int l, int r, int x)
{
    while (l < x) {
        int mid = (l + r) / 2;
        if (x <= getSum(mid)) // getSum(i)返回比i小的序列个数
            r = mid;
        else l = mid + 1;
    }
    return l;
}


int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    memset(c, 0, sizeof(c));
    int x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        update(x, 1); // 更新覆盖v的所有树状数组
    }
    // 找到第k小
    printf("%d\n", binarySearch(1, maxn, k));
    return 0;
}
