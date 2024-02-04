#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int space;

    i = 0;
    space = 1;
    if (argc == 2)
    {
        while (argv[1][i])
        {
            if (argv[1][i] == 32 || (argv[1][i] >= 9 && argv[1][i] <= 13))
            {
                if (!space && argv[1][i+1] != '\0')
                {
                    write(1, "   ", 3);
                    space = 1;
                }
            }
            else
            {
                write(1, &argv[1][i], 1);
                space = 0;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}