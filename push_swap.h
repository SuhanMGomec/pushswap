/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:32:23 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/11 20:39:31 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <unistd.h>
#include <stdlib.h>

char    **ft_split(char const *s, char sep);
void	pb(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void    sa(t_stack **a);
void    sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
int is_valid_number(char *s);
long	ft_atol(const char *s);
int	has_duplicate(t_stack *a, int n);
void	free_split(char **arr);
void	error_exit(t_stack **stack, char **split);
void	add_number(t_stack **stack, char *word, char **split);
t_stack	*parse_args(int argc, char **argv);

typedef struct s_stack
{
    int             content;
    int             index;
    struct s_stack  *next;
}	t_stack;

#endif