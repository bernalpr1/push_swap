#include"push_swap.h"

static  void rotate(t_stack_node **list)
{
    t_stack_node *last;

    last = find_last(*list);
    if (list == NULL || *list == NULL )
		return ;
    last->prev->next = NULL;
    last->next = (*list);
    (*list)->prev = NULL;
    (*list) = last;
    last->next->prev = last;
    
}


void    rra(t_stack_node **a)
{
    rotate(a);
}

void    rrb(t_stack_node **b)
{
    rotate(b);
}

void    rrr(t_stack_node **b, t_stack_node **a)
{
    rotate(a);
    rotate(b);
}
