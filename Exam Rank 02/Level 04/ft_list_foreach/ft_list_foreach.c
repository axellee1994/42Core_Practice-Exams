#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_list.h"

void    ft_list_foreach(t_list *begin_list, void(*f)(void *))
{
    while (begin_list)
    {
        f(begin_list -> data);
        begin_list = begin_list -> next;
    }
}

void    print_int(void  *data)
{
    printf("%d\n", *(int *)data);


int main(void)
{
    t_list *list = NULL;

    t_list *node1 = malloc(sizeof(t_list));
    t_list *node2 = malloc(sizeof(t_list));
    t_list *node3 = malloc(sizeof(t_list));

    int num1;
    int num2;
    int num3;

    num1 = 5;
    num2 = 10;
    num3 = 15;

    node1 -> data = &num1;
    node2 -> data = &num2;
    node3 -> data = &num3;

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
