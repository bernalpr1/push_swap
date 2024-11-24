#include "push_swap.h"

static void push(t_stack_node **pusher, t_stack_node **reciver)
{
    t_stack_node    *node;

    if (*pusher == NULL)
        return;
    node = *pusher;
    *pusher = (*pusher)->next;
    if(*pusher)
        (*pusher)->prev = NULL;
    node->prev = NULL;
    if (*reciver == NULL)
    {
        *reciver = node;
        node->next = NULL;
    }
    else
    {
        node->next = *reciver;
        node->next->prev = node;
        *reciver = node;
    }
}

void    pa(t_stack_node **a, t_stack_node **b)
{
    push(a, b);
}

void    pb(t_stack_node **b, t_stack_node **a)
{
    push(b, a);
}