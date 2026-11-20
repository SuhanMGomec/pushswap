/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:54:12 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:54:13 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	assign_index(t_stack *stack)
{
	t_stack	*lst;
	t_stack	*head;
	int		i;

	head = stack;
	while (stack)
	{
		i = 0;
		lst = head;
		while (lst)
		{
			if (lst->content < stack->content)
				i++;
			lst = lst->next;
		}
		stack->index = i;
		stack = stack->next;
	}
}

double	disorder(t_stack *stack)
{
	t_stack	*lst;
	int		inv;
	int		n;
	double	pairs;

	inv = 0;
	n = 0;
	while (stack)
	{
		n++;
		lst = stack;
		while (lst)
		{
			if (lst->content < stack->content)
				inv++;
			lst = lst->next;
		}
		stack = stack->next;
	}
	if (n < 2)
		return (0);
	pairs = n * (n - 1) / 2.0;
	return (inv / pairs);
}

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
