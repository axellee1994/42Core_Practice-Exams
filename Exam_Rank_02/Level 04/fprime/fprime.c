#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    int i;
    int nbr;

    i = 2;
    if (argc == 2)
    {
        nbr = atoi(argv[1]);
        while (i <= nbr)
        {
            if (nbr % i == 0)
            {
                printf("%d", i);
                nbr /= i;
                if (nbr != 1)
                    printf("*");
            }
            else
                i++;
        }
    }
    printf("\n");
    return (0);
}