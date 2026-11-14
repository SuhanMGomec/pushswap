/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:39:12 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 22:51:23 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	square_root(int n)
{
	int	i;

	i = 1;
	while ((i+1)*(i+1) < n)
		i++;
	return (i);
}


void	sort_first_part(t_stack	**a, t_ctr *ctr)
{
	int	elements;
	int	chunk;
	t_stack	**b;

	chunk = square_root(stack_size(*a));
	elements = 0;
	b = NULL;
	while (*a)
	{
		if ((*a)->index < chunk + elements)
		{
			pb(a,b,ctr);
			elements++;
		}
		else
			ra(a,ctr);
	}
}

void	sort_second_part(t_stack **a, t_stack **b, t_ctr *ctr)
{
	int	size;
	int	i;
	int elements;

	i = find_max_index(*b);
	elements = 0;
	size = stack_size(*b);
	while (*b)
	{
		if (find_pos(*b, i) <= (size - elements) / 2)
		{
			while ((*b)->index != i)
				rb(b, ctr);
		}
		else
		{
			while ((*b)->index != i)
			rrb(b,ctr);
		}
		pa(a,b,ctr);
		i--;
		elements++;
	}
}