#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int nbr1;
    int nbr2;

    if (argc != 3)
    {
        write(1, "\n", 1);
        return (0);
    }
    else if (argc == 3)
    {
        nbr1 = atoi(argv[1]);
        nbr2 = atoi(argv[2]);
        if (nbr1 != 0 && nbr2 != 0)
        {
            while (nbr1 != nbr2)
            {
                if (nbr1 > nbr2)
                    nbr1 -= nbr2;
                else
                    nbr2 -= nbr1;
            }
            printf("%d\n", nbr1);
        }
    }
    return (0);
}