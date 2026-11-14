/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 14:08:21 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 13:07:12 by gucakmak         ###   ########.fr       */
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
	
}
