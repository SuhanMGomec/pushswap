/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 12:17:55 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 13:38:01 by sgomec           ###   ########.fr       */
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