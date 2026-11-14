/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:33:09 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 21:29:55 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	get_max_bits(int size)
{
	int	max;
	int	bits;

	max = size - 1;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

static void	radix_pass(t_stack **a, t_stack **b, int bit, t_ctr *ctr)
{
	int	size;
	int	i;

	i = 0;
	size = stack_size(*a);
	while (i < size)
	{
		if (((*a)->index >> bit) & 1)
			ra (a, ctr);
		else
			pb (a, b, ctr);
		i++;
	}
	while (*b)
		pa(a, b, ctr);
}

void	sort_complex(t_stack **a, t_ctr *ctr)
{
	t_stack	*b;
	int		max_bits;
	int		bit;

	if (is_sorted(*a))
		return ;
	b = NULL;
	bit = 0;
	max_bits = get_max_bits((stack_size(*a)));
	while (bit < max_bits)
	{
		radix_pass(a, &b, bit, ctr);
		if (is_sorted(*a))
			return ;
		bit++;
	}
}
