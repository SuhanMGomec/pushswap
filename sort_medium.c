/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak <gucakmak@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:39:12 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/18 20:10:30 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(int n)
{
	int	i;

	i = 1;
	while ((i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

static void	first_part(t_stack **a, t_stack **b, t_ctr *ctr)
{
	int	i;
	int	chunks;

	i = 0;
	chunks = square_root(stack_size(*a));
	while (*a)
	{
		if ((*a)->index <= chunks + i)
		{
			pb(a, b, ctr);
			if ((*b)->index < i)
				rb(b, ctr);
			i++;
		}
		else
			rra(a, ctr);
	}
}

static void	second_part(t_stack **a, t_stack **b, t_ctr *ctr)
{
	int	i;

	i = find_max_index(*b);
	while (*b)
	{
		if (find_pos(*b, i) <stack_size(*b) / 2)
		{
			while ((*b)->index != i)
				rb(b, ctr);
		}
		else
		{
			while ((*b)->index != i)
				rrb(b, ctr);
		}
		i--;
		pa(a, b, ctr);
	}
}

void	sort_medium(t_stack **a, t_ctr *ctr)
{
	t_stack	*b;

	b = NULL;
	if (is_sorted(*a))
		return ;
	first_part(a, &b, ctr);
	second_part(a, &b, ctr);
}
