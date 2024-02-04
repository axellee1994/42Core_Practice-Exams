#include <unistd.h>

int is_space(char c)
{
    if (c == 32 || c == 9 || c == 10)
        return (1);
    return (0);
}

void    rev_wstr(char *str)
{
    int i;
    int word_start;
    int word_end;

    i = 0;
    while (str[i])
        i++;
    i--;
    while (i >= 0)
    {
        while(i >= 0 && is_space(str[i]))
            i--;
        word_end = i;
        while (i >= 0 && !is_space(str[i]))
            i--;
        word_start = i + 1;
        while (word_start <= word_end)
        {
            write(1, &str[word_start], 1);
            word_start++;
        }
        if (i >= 0)
            write(1, " ", 1);
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
        rev_wstr(argv[1]);
        write(1, "\n", 1);
        return (0);
    }
}