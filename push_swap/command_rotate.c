#include"push_swap.h"

static  void rotate(t_stack_node **list)
{
    t_stack_node *last;

    last = find_last(*list);
    if (list == NULL || *list == NULL )
		return ;
    last->next = *list;
    (*list) = (*list)->next;
    (*list)->prev = NULL;
    last->next->prev = last;
    last->next->next = NULL;
}


void    ra(t_stack_node **a)
{
    rotate(a);
}

void    rb(t_stack_node **b)
{
    rotate(b);
}

void    rr(t_stack_node **b, t_stack_node **a)
{
    rotate(a);
    rotate(b);
}

