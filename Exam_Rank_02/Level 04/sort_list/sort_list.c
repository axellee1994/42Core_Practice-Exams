#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int	swap;
	t_list	*tmp;
	t_list	*p;

	tmp = lst;
	while (tmp)
	{
		p = tmp -> next;
		while (p)
		{
			if ((*cmp)(tmp->data, p->data) == 0)
			{
				swap = tmp->data;
				tmp->data = p->data;
				p->data = swap;
			}
			else
				p = p->next;
		}
		tmp = tmp->next;
	}
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

    node1 -> data = 108;
    node2 -> data = 73;
    node3 -> data = 45;

    node1 -> next = node2;
    node2 -> next = node3;
    node3 -> next = NULL;

    t_list *list = node1;
    list = sort_list(list, ascending);

    while (list)
    {
        printf("%d", list -> data);
        if (list -> next)
            printf(", ");
        list = list -> next;
    }

    free(node1);
    free(node2);
    free(node3);

    return (0);
}
