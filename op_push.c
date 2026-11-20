/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:27 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:29 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack **a, t_stack **b, t_ctr *ctr)
{
	t_stack	*temp;
	t_stack	*new_lst;

	if (!a || !*a || !b)
		return ;
	temp = *a;
	new_lst = (*a)->next;
	temp->next = *b;
	*b = temp;
	*a = new_lst;
	write(1, "pb\n", 3);
	ctr->pb++;
}

void	pa(t_stack **a, t_stack **b, t_ctr *ctr)
{
	t_stack	*temp;
	t_stack	*new_lst;

	if (!b || !*b || !a)
		return ;
	temp = *b;
	new_lst = (*b)->next;
	temp->next = *a;
	*a = temp;
	*b = new_lst;
	write(1, "pa\n", 3);
	ctr->pa++;
}
