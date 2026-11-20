/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:51 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:53 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_number(t_stack **stack, char *word, char **split)
{
	long	n;
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

static int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

static void	set_flag(char *arg, t_opts *opts, t_stack **stack)
{
	if (!ft_strcmp(arg, "--simple"))
		opts->strategy = SIMPLE;
	else if (!ft_strcmp(arg, "--medium"))
		opts->strategy = MEDIUM;
	else if (!ft_strcmp(arg, "--complex"))
		opts->strategy = COMPLEX;
	else if (!ft_strcmp(arg, "--adaptive"))
		opts->strategy = ADAPTIVE;
	else if (!ft_strcmp(arg, "--bench"))
		opts->bench = 1;
	else
		error_exit(stack, NULL);
}

static void	parse_numbers(t_stack **stack, char *arg)
{
	char	**split;
	int		j;

	split = ft_split(arg, ' ');
	if (!split)
		error_exit(stack, NULL);
	if (!split[0])
		error_exit(stack, split);
	j = 0;
	while (split[j])
		add_number(stack, split[j++], split);
	free_split(split);
}

t_stack	*parse_args(int argc, char **argv, t_opts *opts)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			set_flag(argv[i], opts, &stack);
		else
			parse_numbers(&stack, argv[i]);
		i++;
	}
	return (stack);
}
