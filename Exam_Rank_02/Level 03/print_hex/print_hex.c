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
    if(str[i] == '-')
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

int ft_get_hex(int nbr)
{
    char    str[16] = "0123456789abcedf";

    if (nbr > 16)
        ft_get_hex(nbr / 16);
    write(1, &str[nbr % 16], 1);
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        ft_get_hex(ft_atoi(argv[1]));
        write(1, "\n", 1);
        return (0);
    }
}