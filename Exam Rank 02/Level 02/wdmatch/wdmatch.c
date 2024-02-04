#include <unistd.h>
#include <stdio.h>

void    wdmatch(char *s1, char *s2)
{
    int i;
    int j;

    i = 0;
    while (s1[i])
    {
        j = 0;
        while (s2[j])
        {
            if (s1[i] == s2[j])
                i++;
            if (s1[i] == '\0')
            {
                write(1, s1, i);
                return ;
            }
            j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
    if (argc == 3)
        wdmatch(argv[1], argv[2]);
    write(1, "\n", 1);
    return (0);
}