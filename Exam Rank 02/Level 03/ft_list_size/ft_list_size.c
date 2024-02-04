#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "ft_list.h"

int ft_list_size(t_list *begin_list)
{
    if (begin_list == NULL)
        return (0);
    else
        return (1 + ft_list_size(begin_list->next));
}

int main(void)
{
    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    printf("%d\n", ft_list_size(node1));

    free(node1);
    free(node2);
    free(node3);

    return (0);
}