#include "push_swap.h"

static void swap(t_stack_node **list)
{
    int len;

    len = list_len(*list);
    if (*list == NULL || list == NULL || len == 1)
        return ;
    *list = (*list)->next;
    (*list)->prev->prev = *list;
    (*list)->prev->next = (*list)->next;
    if((*list)->next)
        (*list)->next->prev = (*list)->prev; 
    (*list)->next = (*list)->prev;
    (*list)->prev= NULL;
}

void sa(t_stack_node **a)
{
    swap(a);
}

void sb(t_stack_node **b)
{
    swap(b);
}

void ss(t_stack_node **a, t_stack_node **b)
{
    swap(a);
    swap(b);
}