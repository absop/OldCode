#include<stdio.h>


int main()
{
    char buffer[5010];
    gets(buffer);

    int index_last_nonblank = 0;
    int index_last;
    for(index_last = 0; buffer[index_last]; ++index_last) {
        if (buffer[index_last] == ' '){
            index_last_nonblank = index_last + 1;
        }
    }

    int length = index_last - index_last_nonblank;
    printf("%d\n", length);

    return 0;
}
