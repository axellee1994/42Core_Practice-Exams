#include <unistd.h>
#include <stdio.h>

int check_double(char *str, char c, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        if (str[i] == c)
            return (1);
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (argc == 3)
    {
        while (argv[1][i])
        {
            if (!check_double(argv[1], argv[1][i], i))
                write(1, &argv[1][i], 1);
            i++;
        }
        while (argv[2][j])
        {
            if (!check_double(argv[1], argv[2][j], i) && !check_double(argv[2], argv[2][j], j))
                write(1, &argv[2][j], 1);
            j++;
        }
    }
    write(1, "\n", 1);
    return (0);
}