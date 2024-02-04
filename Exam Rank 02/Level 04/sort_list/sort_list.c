#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
    int swap;
    t_list  *tmp;

    tmp = lst;
    while (lst -> next != NULL)
    {
        if ((*cmp)(lst -> data, lst -> next -> data) == 0)
        {
            swap = lst -> data;
            lst -> data = lst -> next -> data;
            lst -> next -> data = swap;
            lst = tmp;
        }
        else
            lst = lst -> next;
    }
    lst = tmp;
    return (lst);
}

int ascending(int a, int b)
{
    return (a <= b);
}

int main(void)
{
    t_list  *node1 = malloc(sizeof(t_list));
    t_list  *node2 = malloc(sizeof(t_list));
    t_list  *node3 = malloc(sizeof(t_list));

    node1 -> data = 3;
    node2 -> data = 2;
    node3 -> data = 1;

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    t_list *list = node1;
    list = sort_list(list, ascending);

    while (list)
    {
        printf("%d", list -> data);
        list = list -> next;
    }

    free(node1);
    free(node2);
    free(node3);

    return (0);
}