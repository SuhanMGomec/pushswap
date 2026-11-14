/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:08:21 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 13:59:16 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a)
{
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_3(t_stack **a)
{
	int	max;

	max = find_max_index(*a);
	if ((*a)->index == max)
		ra(a);
	else if ((*a)->next->index == max)
		rra(a);
	if ((*a)->index > (*a)->next->index)
		sa(a);
}

void	sort_more_4(t_stack **a)
{
	t_stack	*b;
	int		i;
	int		size;

	b = NULL;
	size = stack_size(*a);
	i = 0;
	while (i < size - 3)
	{
		if (find_pos(*a, i) <= (stack_size(*a)/2))
			while ((*a)->index != i)
				ra(a);
		else
			while ((*a)->index !=i)
				rra(a);
		pb(a,&b);
		i++;
	}
	sort_3(a);
	while (b)
		pa(a,&b);
}

void	sort_small(t_stack **a)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else
		sort_more_4(a);
}