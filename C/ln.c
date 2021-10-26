#include <math.h>
#include <stdio.h>

#define BASIC 2
#define MAx_LEN 50

double Input();
double ln(double x);
double transfer(char *str, int &set);

int main(int argc, char const *argv[])
{
    double test;
    while (true) {
        test = Input();
        if (test > 0)
            printf("ln(%g)=%.10lf\n\n", test, ln(test));
        else
            fprintf(stderr, "%s\n\n", "error, not in declared area!");
    }
    return 0;
}

int isdigit(char item) { return item >= '0' && item <= '9'; }
int issymbol(char item)
{
    return item == '+' || item == '-' || item == '*' || item == '/' ||
           item == '<';
}

double transfer(char *str, int &set)
{
    double temp = 0;
    //浪费了两个小时，一个小小的错误竟然是这儿没有初始化
    int cnt, bnt, i, exp;
    for (set = 0; isdigit(str[set]); ++set)
        ;
    cnt = set;

    for (i = 0; i < cnt; ++i) {
        //整数部分
        exp = cnt - i - 1;
        temp += (str[i] - '0') * pow(10, exp);
    }

    if (str[cnt] == '.') {
        for (set = cnt + 1; isdigit(str[set]); ++set)
            ;
        bnt = set - cnt - 1;

        for (i = cnt + 1; i <= cnt + bnt; ++i) {
            //小数部分
            exp = i - cnt;
            temp += (str[i] - '0') * pow(10, -exp);
        }
    }

    return temp;
}

double Input()
{
    char symbol, str[MAx_LEN];
    int set = 0, basic = 0;
    long long cool = 1;
    double former = 0, later = 0;
    gets(str);

    while (!isdigit(str[basic])) ++basic;
    //去除开头空格
    former = transfer(&str[basic], set);
    // 从“空格”后开始

    while (basic + set < MAx_LEN && !issymbol(str[basic + set])) ++set;
    if (basic + set >= MAx_LEN) return former;

    symbol = str[basic + set];

    while (!isdigit(str[basic + set])) ++set;
    later = transfer(&str[basic + set], set);

    printf("%g\t%c\t", former, symbol);
    printf("%g\t=\t", later);

    if (symbol == '+') former += later;
    if (symbol == '-') former -= later;
    if (symbol == '*') former *= later;
    if (symbol == '/') former /= later;
    if (symbol == '<') former *= cool << (int)later;

    printf("%g\n", former);

    return former;
}
double ln(double x)
{
    double sum = 0;
    if (x <= 2) {
        int i = 1;
        double z = (x - 1) / (x + 1);
        double item = 1;
        double temp = z * z;
        while (fabs(item) > 1E-11) {
            item = z / i;
            sum += item;
            z *= temp;
            i += 2;
        }
        sum *= 2;
    }
    else {
        int i = 1;
        long long cool = 1;
        while ((cool << ++i) <= x)
            ;  // 1左移n位等于2的n次方
        cool = cool << --i;
        sum = i * ln(BASIC) + ln(x / cool);

        printf("ln(%g)=%dln(BASIC)+ln(%g/%lld)\n", x, i, x, cool);
    }
    return sum;
}
