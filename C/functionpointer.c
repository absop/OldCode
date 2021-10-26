#include <stdio.h>

#ifdef __GNUC__
const char *compiler_name = "GCC";
// In GCC, function can not return a function,
// Tinycc do it well
// The type of u is function.
// In GCC, we must cast it to a function pointer
// manually so that it could be returned
typedef void (*f1)();
typedef f1 (*f2)();
typedef f2 (*function)();
function u() { return (function)u; }

#else

#ifdef __TINYC__
const char *compiler_name = "TCC";
// In Tinycc, it dose not needed.
// We can straightforward write as:
typedef void f1();
typedef f1 f2();
typedef f2 function();
function u() { return u; }
#endif

#endif

// 一个函数的定义并不在于它返回了什么，而在于它声明的返回类型


int main()
{
    printf("%s\n", compiler_name);
    printf("%p\n", u);
    printf("%p\n", u());
    printf("%p\n", u()());
    printf("%p\n", u()()());
    // printf("%p\n", u()()()());

    return 0;
}
