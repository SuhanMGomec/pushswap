/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gucakmak@student.42istanbul.com.tr         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/03 13:10:57 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 12:01:52 by gucakmak         ###   ########.fr       */
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
