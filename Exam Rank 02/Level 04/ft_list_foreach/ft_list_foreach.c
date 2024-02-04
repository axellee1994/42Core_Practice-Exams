#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        f(begin_list -> data);
        begin_list = begin_list -> next;
    }
}

void    print_int(void *data)
{
    printf("%d\n", *(int *)data);
}

int main(void)
{
    t_list *list = NULL;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int nbr1;
    int nbr2;
    int nbr3;

    nbr1 = 5;
    nbr2 = 10;
    nbr3 = 15;

    node1 -> data = &nbr1;
    node2 -> data = &nbr2;
    node3 -> data = &nbr3;

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    list = node1;

    ft_list_foreach(list, print_int);

    free(node1);
    free(node2);
    free(node3);

    return (0);
}