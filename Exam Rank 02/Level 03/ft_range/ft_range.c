#include <unistd.h>
#include <stdio.h>

int abs(int nbr)
{
    if (nbr < 0)
        return (-nbr);
    else
        return (nbr);
}

int *ft_range(int start, int end)
{
    int i;
    int len;
    int *res;

    i = 0;
    len = abs((end - start) + 1);
    res = (int *)malloc(sizeof(int) * len);
    while (i < len)
    {
        if (start <= end)
        {
            while (start <= end)
            {
                res[i] = start;
                start++;
                i++;
            }
        }
        else if (start >= end)
        {
            while (start >= end)
            {
                res[i] = start;
                start--;
                i++;
            }
        }
    }
    return (res);
}

int main(void)
{
    int *range;

    range = ft_range(1 , 3);
    printf("%d\n", range[0]);
    printf("%d\n", range[1]);
    printf("%d\n", range[2]);

    free(range);
    return (0);
}