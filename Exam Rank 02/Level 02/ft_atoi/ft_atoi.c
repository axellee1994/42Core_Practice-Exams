#include <unistd.h>
#include <stdio.h>

int ft_atoi(const char *str)
{
    int i;
    int result;
    int sign;

    i = 0;
    result = 0;
    sign = 1;

    if (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == '-')
        sign = -1;
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
    {
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return (sign * result);
}

int main(void)
{
    printf("%d\n", ft_atoi("-123"));
    return (0);
}