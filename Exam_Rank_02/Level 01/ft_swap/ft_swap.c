#include <unistd.h>
#include <stdio.h>

void    ft_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

int main(void)
{
    int t1;
    int t2;

    t1 = 12;
    t2 = 24;
    ft_swap(&t1, &t2);
    printf("%d\n", t1);
    printf("%d\n", t2);
    return (0);
}