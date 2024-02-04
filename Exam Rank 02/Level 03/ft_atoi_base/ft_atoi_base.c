#include <unistd.h>
#include <stdio.h>

char    ft_lowercase(char c)
{
    if (c >= 'A' && c <= 'F')
        c += 32;
    return (c);
}

int ft_get_hex(char c, int str_base)
{
    char    digit;
    if (c >= '0' && c <= '9')
        digit = c - '0';
    else if (c >= 'a' && c <= 'f')
        digit = c - 'a' + 10;
    else
        return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i;
    int result;
    int sign;
    int digit;

    i = 0;
    result = 0;
    sign = 1;
    if (str[i] == 32 || str[i] == 9)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (sign == '+')
        i++;
    digit = ft_get_hex(ft_lowercase(str[i]), str_base);
    while (digit >= 0)
    {
        result = result * str_base + digit;
        i++;
        digit = ft_get_hex(ft_lowercase(str[i]), str_base);
    }
    return (sign * result);
}

int main(void)
{
    printf("%d\n", ft_atoi_base("-7F", 16));
    return (0);
}