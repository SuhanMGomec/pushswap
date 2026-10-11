/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:46:24 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/11 20:50:34 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*temp;
	
	if (argc < 2)
		return (0);
	a = parse_args(argc,argv);
	temp = a;
	while (temp)
	{
		printf("%d",temp->content);
		temp = temp->next;
	}
	free_stack(&a);
	return (0);
}