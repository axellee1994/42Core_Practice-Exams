#include <unistd.h>
#include <stdio.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    int temp;

    i = 0;
    len = 0;
    while (str[len])
        len++;
    len--;
    while (i < len)
    {
        temp = str[i];
        str[i] = str[len];
        str[len] = temp;
        i++;
        len--;
    }
    return (str);
}

int main(void)
{
    char    *result;
    char    src[] = "Hello Axel";

    result = ft_strrev(src);
    printf("%s\n", result);
    return (0);
}