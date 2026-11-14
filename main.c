/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:46:24 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 21:50:25 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
