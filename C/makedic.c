#include <stdio.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>


void makedic(char *str, int len)
{
    int lenstr = strlen(str);
    int lenkey = len + 1;
    int p = (int)pow(lenstr, len);
    int lenseg = p * (lenkey) / lenstr;
    char *buffer = (char *)malloc(lenseg);

    int i, j, s = 0;
    int lenblock, end, time = 1;
    char c;

    for (i = len; i < lenseg; i += lenkey)
        buffer[i] = '\n';
    for (; --len >= 0; time *= lenstr) {
        lenblock = time * lenkey;
        for (s = 0, i = len; i < lenseg; i += lenblock) {
            c = str[s++];
            end = time * lenkey + i;
            if (s >= lenstr) s = 0;
            for (j = i; j < end; j += lenkey)
                buffer[j] = c;
        }
    }

    FILE *fp = fopen("dic.txt", "wb+");
    fwrite(buffer, lenseg, 1, fp);

    for (int k = 1; k < lenstr; ++k) {
        c = str[k];
        for (int i = 0; i < lenseg; i += lenkey)
            buffer[i] = c;
        fwrite(buffer, lenseg, 1, fp);
    }
    fclose(fp);
}
int main()
{
    time_t start = clock();
    printf("生成中 . . . ");
    makedic("0123456789", 4);
    printf("Done. (%.3f s)\n", (clock() - start) * 1.0 / CLOCKS_PER_SEC);
    return 0;
}
