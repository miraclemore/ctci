#include <stdio.h>
#include <string.h>

int reverse(char *str)
{
    int length;
    char *start, *end, tmp;

    if (!str) {
        return -1;
    }

    length = strlen(str);
    start = str;
    end = str + length - 1;

    while (start < end) {
        tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }

    return 0;
}

int main(void)
{
    char str[] = "1234567890";

    reverse(str);

    printf("%s\n", str);

    return 0;
}
