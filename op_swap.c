/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:43 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:44 by sgomec           ###   ########.fr       */
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

void	sa(t_stack **a, t_ctr *ctr)
{
	swap(a);
	write(1, "sa\n", 3);
	ctr->sa++;
}

void	sb(t_stack **b, t_ctr *ctr)
{
	swap(b);
	write(1, "sb\n", 3);
	ctr->sb++;
}

void	ss(t_stack **a, t_stack **b, t_ctr *ctr)
{
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
	ctr->ss++;
}
