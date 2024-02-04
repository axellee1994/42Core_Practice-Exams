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
    if (str[i] == 32 || str[i] == 9)
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

void    ft_putnbr(int nbr)
{
    char    digit;
    if (nbr > 9)
        ft_putnbr(nbr / 10);
    digit = (nbr % 10) + '0';
    write(1, &digit, 1);
}

int ft_isprime(int nbr)
{
    int i;

    i = 2;
    if (nbr <= 1)
        return (0);
    while (i * i <= nbr)
    {
        if (nbr % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int main(int argc, char **argv)
{
    int nbr;
    int sum;

    if (argc == 2)
    {
        nbr = ft_atoi(argv[1]);
        sum = 0;
        while (nbr != 0)
        {
            if (ft_isprime(nbr))
                sum += nbr;
            nbr--;
        }
        ft_putnbr(sum);
    }
    write(1, "\n", 1);
    return (0);
}