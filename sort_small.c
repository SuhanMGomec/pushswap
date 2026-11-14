/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:08:21 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 11:22:44 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_max_index(t_stack *a)
{
	int	max;

	max = a->index;
	while (a)
	{
		if (a->index > max)
			max = a->index;
		a = a->next;
	}
	return (max);
}

static int	find_pos(t_stack *a, int index)
{
	int	pos;

	pos = 0;
	while (a && a->index != index)
	{
		a = a->next;
		pos++;
	}
	return (pos);
}

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

void	sort_5(t_stack **a)
{
	t_stack	*b;
	int		size;
	int		i;

	b = NULL;
	size = stack_size(*a);
	i = 0;
	while (i < size - 3)
	{
		if (find_pos(*a, i) <= stack_size(*a) / 2)
			while ((*a)->index != i)
				ra(a);
		else
			while ((*a)->index != i)
				rra(a);
		pb(a, &b);
		i++;
	}
	sort_3(a);
	while (b)
		pa(a, &b);
}
