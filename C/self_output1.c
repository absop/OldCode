#include <stdio.h>

typedef struct {
    FILE *(*open)(const char *, const char *);
    int (*getchar)(FILE *);
    int (*close)(FILE *);
} FS;

FS fs = { &fopen, &getc, &fclose };

typedef struct {
    int (*print)(int);
    int (*printf)(const char *fmt, ...);
} SCREEN;

SCREEN screen = { &putchar, &printf };

int main()
{
    FILE *fp;
    char c;
    fp = fs.open(__FILE__ , "r");
    while ((c = fs.getchar(fp)) != EOF)
        screen.print(c) ;
    // screen.printf("File: %s print done.\n", __FILE__);

    fs.close(fp);
    return 0;
}
