#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>

typedef struct s_stack_node
{
    int                 value;
    int                 current;
    int                 desired;
    int                 price;
    struct s_stack_node *target_node;
    struct s_stack_node *next;
    struct s_stack_node *prev;
}               t_stack_node;


void	stack_init(t_stack_node **a, char **argv, bool flag_argc_2);
char    **ft_parser(char *str, char separator);
int	    error_repeat(t_stack_node *a, int nbr);
int     error_syntax(char *nbrs);
void    error_free(t_stack_node **a, char **argv, bool flag_argc_2);
void    free_matrix(char **argv);
void    add_node(t_stack_node **stack, int nbr);
void    show(t_stack_node *a, t_stack_node *b);
int     list_len(t_stack_node *stack);
t_stack_node *find_last(t_stack_node *cursor);

void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void            rr(t_stack_node **b, t_stack_node **a);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);

#endif