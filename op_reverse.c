/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:35 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:37 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	lst = *stack;
	while (lst->next->next != NULL)
		lst = lst->next;
	temp = lst->next;
	lst->next = NULL;
	temp->next = *stack;
	*stack = temp;
}

void	rra(t_stack **a, t_ctr *ctr)
{
	reverse(a);
	write(1, "rra\n", 4);
	ctr->rra++;
}

void	rrb(t_stack **b, t_ctr *ctr)
{
	reverse(b);
	write(1, "rrb\n", 4);
	ctr->rrb++;
}

void	rrr(t_stack **a, t_stack **b, t_ctr *ctr)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
	ctr->rrr++;
}
