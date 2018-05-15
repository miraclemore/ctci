#include <stdio.h>
#include <string.h>

/* 1: unique */
int is_unique_char(char *str)
{
    int i = 0;
    int length = strlen(str);
    int count[256] = {0};

    memset(count, 0, 256);

    if (!str) {
        return -1;
    }

    if (strlen(str) > 256)
        return 0;

    for (i = 0; i < length; i++) {
        count[(int)str[i]]++;
    }

    for (i = 0; i < 256; i++) {
        if (count[i] > 1) {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    char str1[] = "123143;;'retrerwte";
    char str2[] = "1234567890";

    if (is_unique_char(str1) == 1) {
        printf("str1 is unique\n");
    } else {
        printf("str1 is not unique\n");
    }

    if (is_unique_char(str2) == 1) {
        printf("str2 is unique\n");
    } else {
        printf("str2 is not unique\n");
    }

    return 0;
}
