#include <unistd.h>
#include <stdio.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i;

    i = 0;
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
    return (s1);
}

int main(void)
{
    char    t1[] = "Hello";
    char    t2[] = "Waaaa";
    char    *result;

    result = ft_strcpy(t1, t2);
    printf("%s\n", result);
    return (0);
}