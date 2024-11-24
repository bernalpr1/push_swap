#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (1 == argc || (2 == argc && !argv[1][0]))
		return (1);
	else if (2 == argc)
		argv = ft_parser(argv[1], ' ');

	
	stack_init(&a, argv + 1, 2 == argc);
	show(a , b);
	rra(&a);
	pa(&a,&b);
	pa(&a,&b);
	pa(&a,&b);
	show(a , b);
	rrb(&b);
	show(a , b);
	pb(&b, &a);
	show(a , b);
	
	return (1);
}

    