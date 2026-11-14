/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   main.c                                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: gucakmak <gucakmak@student.42istanbul.com.#+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 20:46:24 by gucakmak         #+#    #+#              */
/*   Updated: 2026/11/11 15:24:08 by gucakmak        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_stack(t_stack **a)
{
	int	size;

	if (is_sorted(*a))
		return ;
	size = stack_size(*a);
	if (size == 2)
		sort_2(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4 || size == 5)
		sort_5(a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;

	if (argc < 2)
		return (0);
	a = parse_args(argc, argv);
	assign_index(a);
	sort_stack(&a);
	free_stack(&a);
	return (0);
}
