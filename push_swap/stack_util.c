#include "push_swap.h"

t_stack_node *find_last(t_stack_node *cursor)
{
    if (cursor == NULL)
        return (NULL);
    while (cursor->next)
        cursor = cursor->next;
    return(cursor);
}

void    add_node(t_stack_node **stack, int nbr)
{
    t_stack_node    *node;
    t_stack_node    *prev_node;

    if (stack == NULL)
        return ;
    node = malloc(sizeof (t_stack_node));
    if (node == NULL)
        return ;
    node->next = NULL;
    node->value = nbr;
    if (*stack == NULL)
    {
        *stack = node;
        node->next = NULL;
        node->prev = NULL;
    }
    else
    {
        prev_node = find_last(*stack);
        prev_node->next = node;
        node->prev = prev_node;
        node->next = NULL;
    }
}

int list_len(t_stack_node *stack)
{
    int i;

    i = 0;
    if (stack == NULL)
        return (0);
    while (stack)
    {
        stack = stack->next;
        i++;
    }
    return(i);
}
/*void    show(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *j;
    t_stack_node *p;

    j = a;
    p = b;

	while(j)
	{	
        if(j == a)
            printf("stack A:\n");
		printf("%i", j->value);
        printf("\n");
		j = j->next;
	}
    printf("\n");
    while (p)
    {
        if(p == b)
            printf("stack B:\n");
        printf("%i", p->value);
        printf("\n");
        p = p->next;
    }
    printf("\n");
}*/

int stack_size(t_stack_node *stack) {
    int size = 0;
    while (stack) {
        size++;
        stack = stack->next;
    }
    return size;
}

// side by side
void show(t_stack_node *a, t_stack_node *b) {
    t_stack_node *stack_a = a;
    t_stack_node *stack_b = b;

    int size_a = stack_size(stack_a);
    int size_b = stack_size(stack_b);

    // Print statistics
    printf("Statistics:\n");
    printf("Stack A size: %d\n", size_a);
    printf("Stack B size: %d\n", size_b);
    printf("\n");

    printf("Stack A\t\tStack B\n");
    printf("----------------------------\n");

    // Print both stacks side by side
    while (stack_a || stack_b) {
        if (stack_a) {
            printf("%d\t\t", stack_a->value);
            stack_a = stack_a->next;
        } else {
            printf("null\t\t");
        }

        if (stack_b) {
            printf("%d\n", stack_b->value);
            stack_b = stack_b->next;
        } else {
            printf("null\n");
        }
    }
    printf("\n");
}