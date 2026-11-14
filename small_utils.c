/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:17:55 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 12:19:53 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_index(t_stack *a)
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

int	find_pos(t_stack *a, int index)
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