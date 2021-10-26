#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


void permute(char *str, int len)
{
    int lenstr = strlen(str);
    int length_key = len + 1;
    int p = (int)pow(lenstr, len);
    int length_segment = p * (length_key) / lenstr;
    char *buffer = (char *)malloc(length_segment);

    int i, j, s = 0;
    int lenblock, end, time = 1;
    char c;

    for (i = len; i < length_segment; i += length_key)
        buffer[i] = '\n';
    for (; --len >= 0; time *= lenstr) {
        lenblock = time * length_key;
        for (s = 0, i = len; i < length_segment; i += lenblock) {
            c = str[s++];
            end = time * length_key + i;
            if (s >= lenstr) s = 0;
            for (j = i; j < end; j += length_key)
                buffer[j] = c;
        }
    }

    FILE *fp = fopen("dic.txt", "wb+");
    fwrite(buffer, length_segment, 1, fp);

    for (int k = 1; k < lenstr; ++k) {
        c = str[k];
        for (int i = 0; i < length_segment; i += length_key)
            buffer[i] = c;
        fwrite(buffer, length_segment, 1, fp);
    }

    fclose(fp);
}


int main()
{
    permute("12345", 3);

    return 0;
}
