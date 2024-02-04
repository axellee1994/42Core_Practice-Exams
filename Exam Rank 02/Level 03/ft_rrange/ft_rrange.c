#include <unistd.h>
#include <stdio.h>

int *ft_rrange(int start, int end)
{
    int i;
    int len;
    int *result;

    i = 0;
    len - abs ((end - start) + 1);
    result = (int *)malloc(sizeof (int) * len);
    while (i < len)
    {
        if (start < end)
        {
            result[i] = end;
            end--;
            i++;
        }
        else
        {
            result[i] = end;
            end++;
            i++;
        }
    }
    return (result);
}

int main(void)
{
    int *range;

    range = ft_rrange(1, 3);
    printf("%d\n", range[0]);
    printf("%d\n", range[1]);
    printf("%d\n", range[2]);

    free(range);
    return (0);

}
