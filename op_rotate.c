/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:39 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:41 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*lst;
	t_stack	*new_lst;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp = *stack;
	lst = (*stack)->next;
	new_lst = lst;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = temp;
	temp->next = NULL;
	*stack = new_lst;
}

void	ra(t_stack **a, t_ctr *ctr)
{
	rotate(a);
	write(1, "ra\n", 3);
	ctr->ra++;
}

void	rb(t_stack **b, t_ctr *ctr)
{
	rotate(b);
	write(1, "rb\n", 3);
	ctr->rb++;
}

void	rr(t_stack **a, t_stack **b, t_ctr *ctr)
{
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	ctr->rr++;
}
