#include <stdio.h>
#include <string.h>

int replace(char *str, char src, char *dst)
{
    int i, j, t;
    int length, newlength, dstlength, count;

    if (!str) {
        return -1;
    }

    count = 0;
    i = 0;

    while (str[i] != '\0') {
        if (str[i] == src) {
            count++;
        }
        i++;
    }

    /* calculate the new strlen */
    length = strlen(str);
    newlength = length + count * (strlen(dst) - 1);

    /* The replaced strlen */
    dstlength = strlen(dst);

    str[newlength] = '\0';
    j = newlength;

    for (i = length - 1; i > 0; i--) {
        if (str[i] == src) {
            t = dstlength - 1;
            while(t >= 0) {
                str[j--] = dst[t--];
            }
        } else {
            str[j--] = str[i];
        }
    }

    return 0;
}

int main(void)
{
    char teststr[100] = "abc cde fgh ijk ";
    replace(teststr, ' ', "123");

    printf("%s\n", teststr);
    return 0;
}
