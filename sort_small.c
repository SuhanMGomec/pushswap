/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:08:21 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/17 14:58:12 by sgomec           ###   ########.fr       */
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
		while ((*a)->index != i)
			ra(a);
		pb(a,&b);
		i++;
	}
	sort_3(a);
	while (b)
		pa(a,&b);
}