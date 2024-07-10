#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;

    i = 0;
    if (argc == 2)
    {
        while(argv[1][i] == 32 || argv[1][i] >= 9 && argv[1][i] <= 13)
            i++;
        while (argv[1][i])
        {
            if (argv[1][i] == 32 || argv[1][i] == 9)
                break;
            else
                write(1, &argv[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}