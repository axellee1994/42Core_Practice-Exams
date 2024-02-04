#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char    *ft_strrev(char *str)
{
    int i;
    int len;
    int temp;

    i = 0;
    len = 0;
    while(str[len])
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

char    *ft_itoa(int nbr)
{
    int i;
    int sign;
    char *str;

    i = 0;
    sign = 1;
    str = malloc(12);
    if (!str)
        return (NULL);
    if (nbr == -2147483648)
    {
        str = "-2147483648";
        return (str);
    }
    if (nbr < 0)
    {
        sign = -1;
        nbr = -nbr;
    }
    if (nbr == 0)
    {
        str[i] = '0';
        i++;
    }
    while (nbr != 0)
    {
        str[i] = nbr % 10 + '0';
        i++;
        nbr /= 10;
    }
    if (sign == -1)
    {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    ft_strrev(str);
    return (str);
}

int main(void)
{
    int nbr;
    char    *result;

    nbr = -1234;
    result = ft_itoa(nbr);
    printf("%s\n", result);
    free(result);
    return(0);
}
