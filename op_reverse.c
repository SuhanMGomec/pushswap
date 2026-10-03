/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:10:59 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/03 15:29:02 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	if (!stack || !*stack || !(*stack)->next)
		return ;
	t_stack	*temp;
	t_stack	*lst;

	lst = *stack;
	while (lst->next->next != NULL)
		lst = lst->next;
	temp = lst->next;
	lst->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	rra(t_stack **a)
{
	reverse(a);
	write (1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	reverse(b);
	write (1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	reverse(a);
	reverse(b);
	write (1, "rrr\n", 4);
}