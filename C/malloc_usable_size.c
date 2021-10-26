#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <malloc.h>


/* default memory allocation functions with memory limitation */
static inline size_t my_malloc_usable_size(void *ptr)
{
#if defined(__APPLE__)
    return malloc_size(ptr);
#elif defined(_WIN32)
    return _msize(ptr);
#elif defined(EMSCRIPTEN)
    return 0;
#elif defined(__linux__)
    return malloc_usable_size(ptr);
#else
    /* change this to `return 0;` if compilation fails */
    return malloc_usable_size(ptr);
#endif
}


int main()
{
    char *ptr = (char*)malloc(1);
    printf("%lu\n", my_malloc_usable_size(ptr));
    printf("%lu\n", *(size_t*)(ptr - 8));

    free(ptr);

    return 0;
}
