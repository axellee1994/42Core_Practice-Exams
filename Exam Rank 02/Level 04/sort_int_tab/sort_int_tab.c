#include <unistd.h>
#include <stdio.h>

void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i;
    int temp;

    i = 0;
    while (i < (size - 1))
    {
        if (tab[i] > tab[i + 1])
        {
            temp = tab[i];
            tab[i] = tab[i + 1];
            tab[i + 1] = temp;
            i = 0;
        }
        else
            i++;
    }
}

int main(void)
{
    int tab[] = {5,3,6,1,9,2};
    int i;
    unsigned int size;

    i = 0;
    size = sizeof(tab) / sizeof(tab[0]);
    sort_int_tab(tab, size);
    while (i < size)
    {
        printf("%d", tab[i]);
        i++;
    }
    return (0);
}