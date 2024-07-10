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

    while (str[i] == 32 || str[i] >= 9 && str[i] <= 13)
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

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

void    tab_mult(int nbr)
{
    int i;

    i = 1;
    while (i < 9)
    {
        ft_putnbr(i);
        ft_putstr(" x ");
        ft_putnbr(nbr);
        ft_putstr(" = ");
        ft_putnbr(i * nbr);
        ft_putstr("\n");
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1 , "\n", 1);
        return (0);
    }
    else
        tab_mult(ft_atoi(argv[1]));
    return (0);
}