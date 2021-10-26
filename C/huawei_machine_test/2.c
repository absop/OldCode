#include<stdio.h>

#define isupper(ch) (('A' <= (ch)) && ((ch) <= 'Z'))
#define islower(ch) (('a' <= (ch)) && ((ch) <= 'z'))
#define tolower(ch) ((ch) - 'A' + 'a')
#define toupper(ch) ((ch) - 'a' + 'A')

int count[128] = {0};

int get_num(char c)
{
    if (isupper(c))
        return count[tolower(c)] + count[c];
    else if (islower(c))
        return count[toupper(c)] + count[c];
    else
        return count[c];
}

int main()
{
    int ch;
    while ((ch = getchar()) != '\n') {
        count[ch] += 1;
    }

    ch = getchar();
    printf("%d\n", get_num(ch));

    return 0;
}
