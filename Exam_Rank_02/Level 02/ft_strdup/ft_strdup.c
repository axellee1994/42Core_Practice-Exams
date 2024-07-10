#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char    *ft_strdup(char *src)
{
    int i;
    int len;
    char *strcpy;

    i = 0;
    len = 0;
    while (src[len])
        len++;
    strcpy = malloc(len + 1);
    if (strcpy != NULL)
    {
        while (src[i])
        {
            strcpy[i] = src[i];
            i++;
        }
        strcpy[i] = '\0';
        return (strcpy);
    }
    return (NULL);
}

int main(void)
{
    char    src[] = "Hello";
    char    *dst;

    dst = ft_strdup(src);
    if (dst != NULL)
    {
        printf("%s\n", dst);
        free (dst);
    }
    return (0);
}