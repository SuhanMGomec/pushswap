/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:08:21 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 19:28:59 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_stack **a, t_ctr *ctr)
{
	if ((*a)->index > (*a)->next->index)
		sa(a, ctr);
}

void	sort_3(t_stack **a, t_ctr *ctr)
{
	int	max;

	max = find_max_index(*a);
	if ((*a)->index == max)
		ra(a, ctr);
	else if ((*a)->next->index == max)
		rra(a, ctr);
	if ((*a)->index > (*a)->next->index)
		sa(a, ctr);
}

void	sort_more_4(t_stack **a, t_ctr *ctr)
{
	t_stack	*b;
	int		i;
	int		size;

	b = NULL;
	size = stack_size(*a);
	i = 0;
	while (i < size - 3)
	{
		if (find_pos(*a, i) <= (stack_size(*a) / 2))
			while ((*a)->index != i)
				ra(a, ctr);
		else
			while ((*a)->index != i)
				rra(a, ctr);
		pb(a, &b, ctr);
		i++;
	}
	sort_3(a, ctr);
	while (b)
		pa(a, &b, ctr);
}

void	sort_simple(t_stack **a, t_ctr *ctr)
{
	int	size;

	size = stack_size(*a);
	if (is_sorted(*a))
		return ;
	else if (size == 2)
		sort_2(a, ctr);
	else if (size == 3)
		sort_3(a, ctr);
	else
		sort_more_4(a, ctr);
}
