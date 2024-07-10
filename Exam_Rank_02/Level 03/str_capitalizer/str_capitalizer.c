#include <unistd.h>
#include <stdio.h>

void    str_capitalizer(char *str)
{
    int i;
    int previous_char;

    i = 0;
    while (str[i])
    {
        previous_char = str[i - 1];
        if (i == 0 || previous_char == 32 || previous_char == 9 || previous_char == 10)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                str[i] -= 32;
        }
        else if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
    {
        while (i < argc)
        {
            str_capitalizer(argv[i]);
            write(1, "\n", 1);
            i++;
        }
    }
    return (0);
}