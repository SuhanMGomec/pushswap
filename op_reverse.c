/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:10:59 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 12:02:25 by gucakmak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*stack;

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
	ct->rrr++;
}
