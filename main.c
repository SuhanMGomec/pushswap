/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:46:24 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 21:56:32 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a, t_ctr *ctr)
{
	if (is_sorted(*a))
		return ;
	if (stack_size(*a) <= 5)
		sort_simple(a, ctr);
	else
		sort_complex(a, ctr);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_ctr	ctr;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	assign_index(a);
	init_counter(&ctr);
	sort_stack(&a, &ctr);
	free_stack(&a);
	return (0);
}