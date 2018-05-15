#include <stdio.h>
#include <string.h>

int exchange(char *p, char *q)
{
    char tmp;

    tmp = *p;
    *p = *q;
    *q = tmp;

    return 0;
}

int sort(char *str)
{
    int length;
    int i, j;

    if (!str) {
        return -1;
    }

    length = strlen(str);

    for (i = 0; i < length - 1; i++) {
        for (j = i + 1; j < length; j++) {
            if (str[i] > str[j]) {
                exchange(&str[i], &str[j]);
            }
        }
    }

    return 0;
}

int main(void)
{
    char str1[] = "9876532140";
    char str2[] = "0123456789";

    sort(str1);

    printf("%s\n", str1);

    if (strcmp(str1, str2) == 0) {
        printf("after sort, it is equal!\n");
    } else {
        printf("after sort, it is not equal\n");
    }

    return 0;
}
