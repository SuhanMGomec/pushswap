/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:32:31 by sgomec            #+#    #+#             */
/*   Updated: 2026/10/11 20:32:33 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_stack **stack, char *word, char **split)
{
	long		n;
	t_stack	*new;

	if (!is_valid_number(word))
		error_exit(stack, split);
	n = ft_atol(word);
	if (n > 2147483647 || n < -2147483648)
		error_exit(stack, split);
	if (has_duplicate(*stack, n))
		error_exit(stack, split);
	new = lst_new(n);
	if (!new)
		error_exit(stack, split);
	add_back(stack, new);
}

t_stack	*parse_args(int argc, char **argv)
{
	t_stack	*stack;
	char	**split;
	int		i;
	int		j;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (!split)
			error_exit(&stack, NULL);
		if (!split[0])
			error_exit(&stack, split);
		while (split[j])
			add_number(&stack, split[j++], split);
		free_split(split);
		i++;
	}
	return (stack);
}

