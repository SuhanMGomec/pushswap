/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   op_swap.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: gucakmak <gucakmak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/03 13:11:04 by gucakmak         #+#    #+#              */
/*   Updated: 2026/11/11 15:23:56 by gucakmak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*lst;
	t_stack	*temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst = *stack;
	temp = lst->next;
	lst->next = temp->next;
	temp->next = lst;
	*stack = temp;
}

void	sa(t_stack **a)
{
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
