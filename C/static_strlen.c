#include <stdio.h>

#define static_strlen(string_literal) (sizeof(string_literal) - sizeof(""))
const char *strings[4] = { "Up", "Left", "Down", "Right" };

int main()
{
    printf("%d\n", static_strlen("/*8888*/"));
    return 0;
}
