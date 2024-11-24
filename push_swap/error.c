#include "push_swap.h"

void    free_matrix(char **argv)
{
    int i;

    i = -1;
    if (argv == NULL || *argv == NULL)
        return;
    while (argv[i])
        free(argv[i++]);
    free(argv - 1);
}

void    free_stack(t_stack_node **stack)
{
    t_stack_node *temp;
    t_stack_node *current;

    if (stack == NULL)
        return;
    current = *stack;
    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
    *stack = NULL;
}

void error_free(t_stack_node **a, char **argv, bool flag_argc_2)
{
    free_stack(a);
    if (flag_argc_2)
        free_matrix(argv);
    perror("ERROR\n");
    exit(1);
}

int error_syntax(char *nbrs)
{
    if(!(*nbrs == '+' || *nbrs == '-' || (*nbrs >= '0' && *nbrs <= '9')))
        return(1);
    if ((*nbrs == '+' || *nbrs == '-') && !(nbrs[1] >= '0' && nbrs[1] <= '9'))
		return (1);
    while (*++nbrs)
	{
		if (!(*nbrs >= '0' && *nbrs <= '9'))
			return (1);
	}
	return (0);
}

int	error_repeat(t_stack_node *a, int nbr)
{
	if (a == NULL)
		return (0);
	while (a)
	{
		if (a->value == nbr)
			return (1);
		a = a->next;
	}
	return (0);
}

