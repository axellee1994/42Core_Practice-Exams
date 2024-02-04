#include <stdio.h>
#include <unistd.h>

int is_space(char c)
{
    if (c == 32 || c == 9 || c = 10)
        return (1);
    return (0);
}

void    rostring(char *str)
{
    int i;
    int first_word_len;

    i = 0;
    first_word_len = 0;
    while (str[i])
        i++;
    while (str[i] && !is_space(str[i]))
    {
        i++;
        first_word_len++;
    }
    while (str[i])
    {
        while (str[i] && !is_space(str[i]) && is_space(str[i - 1]))
        {
            while (str[i] && !is_space(str[i]))
            {
                write(1, &str[i], 1);
                i++;
            }
            write(1, " ", 1);
        }
        i++;
    }
    i = 0;
    while (str[i])
        i++;
    while (first_word_len--)
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        write(1, "\n", 1);
        return (0);
    }
    else
    {
        rostring(argv[1]);
        write(1, "\n", 1);
        return (0);
    }
}