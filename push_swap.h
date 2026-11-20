/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:54:00 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:54:02 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# define ADAPTIVE 0
# define SIMPLE 1
# define MEDIUM 2
# define COMPLEX 3

typedef struct s_opts
{
	int	strategy;
	int	bench;
}	t_opts;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_counter
{
	int	sa;
	int	ra;
	int	rra;
	int	pa;
	int	pb;
	int	rrb;
	int	rb;
	int	sb;
	int	ss;
	int	rr;
	int	rrr;
}	t_ctr;

void	init_counter(t_ctr *ctr);
char	**ft_split(char const *s, char sep);
void	pb(t_stack **a, t_stack **b, t_ctr *ctr);
void	pa(t_stack **a, t_stack **b, t_ctr *ctr);
void	rra(t_stack **a, t_ctr *ctr);
void	rrb(t_stack **b, t_ctr *ctr);
void	rrr(t_stack **a, t_stack **b, t_ctr *ctr);
void	ra(t_stack **a, t_ctr *ctr);
void	rb(t_stack **b, t_ctr *ctr);
void	rr(t_stack **a, t_stack **b, t_ctr *ctr);
void	sa(t_stack **a, t_ctr *ctr);
void	sb(t_stack **b, t_ctr *ctr);
void	ss(t_stack **a, t_stack **b, t_ctr *ctr);
int		is_valid_number(char *s);
long	ft_atol(const char *s);
int		has_duplicate(t_stack *a, int n);
void	free_split(char **arr);
void	error_exit(t_stack **stack, char **split);
void	add_number(t_stack **stack, char *word, char **split);
t_stack	*parse_args(int argc, char **argv, t_opts *opts);
t_stack	*lst_new(int content);
void	add_back(t_stack **stack, t_stack *node);
int		stack_size(t_stack *stack);
void	free_stack(t_stack **stack);
int		is_sorted(t_stack *stack);
void	assign_index(t_stack *stack);
double	disorder(t_stack *stack);
void	sort_simple(t_stack **a, t_ctr *ctr);
void	sort_medium(t_stack **a, t_ctr *ctr);
void	sort_complex(t_stack **a, t_ctr *ctr);
int		find_max_index(t_stack *a);
int		find_pos(t_stack *a, int index);
void	bench(double disorder, t_ctr *ctr, char *strategy);

#endif
