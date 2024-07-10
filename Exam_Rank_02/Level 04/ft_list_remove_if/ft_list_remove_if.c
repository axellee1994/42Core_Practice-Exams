#include <unistd.h>
#include <stdlib.h>
#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *temp;

    if (*begin_list)
    {
        if ((*cmp)((*begin_list)->data, data_ref) == 0)
        {
            temp = *begin_list;
            *begin_list = (*begin_list)->next;
            free(temp);
            ft_list_remove_if(begin_list, data_ref, cmp);
        }
        else
            ft_list_remove_if(&(*begin_list)->next, data_ref, cmp);
    }
}

// Comparison and Int Main
int cmp(void *a, void *b)
{
    int int_a;
    int int_b;

    int_a = *((int *)a);
    int_b = *((int *)b);
    if (int_a == int_b)
        return (0);
    else
        return (int_a - int_b);

}

int main(void)
{

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int nbr1;
    int nbr2;
    int nbr3;

    nbr1 = 5;
    nbr2 = 5;
    nbr3 = 4;

    node1 -> data = &nbr1;
    node2 -> data = &nbr2;
    node3 -> data = &nbr3;

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    int data_ref;

    data_ref = 5;
    ft_list_remove_if(&node1, &data_ref, (cmp));

    t_list *temp;
    temp = node1;
    while (temp != NULL)
    {
        printf("%d", *(int *)(temp -> data));
        temp = temp -> next;
    }

    while(node1)
    {
        temp = node1;
        node1 = node1 -> next;
        free (temp);
    }
    return (0);
}
