/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:11:01 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 11:31:32 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void rotate(t_stack **stack)
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

void	ra(t_stack **a)
{
	rotate(a);
	write (1, "ra\n", 3);
	
}

void	rb(t_stack **b)
{
	rotate(b);
	write (1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
	write (1, "rr\n", 3);
}