/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 11:59:06 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/11 18:30:12 by gucakmak         ###   ########.fr       */
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
	int	pairs;

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
	return ((double) inv / pairs);
}
