/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 20:46:24 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 22:20:30 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*run_adaptive(t_stack **a, t_ctr *ctr, double dis)
{
	if (stack_size(*a) <= 5 || dis < 0.2)
	{
		sort_simple(a, ctr);
		return ("Adaptive / O(n^2)");
	}
	if (dis < 0.5)
	{
		sort_medium(a, ctr);
		return ("Adaptive / O(n*sqrt(n))");
	}
	sort_complex(a, ctr);
	return ("Adaptive / O(n*log(n))");
}

static char	*sort_stack(t_stack **a, t_ctr *ctr, int strategy, double dis)
{
	if (strategy == SIMPLE)
	{
		sort_simple(a, ctr);
		return ("Simple / O(n^2)");
	}
	if (strategy == MEDIUM)
	{
		sort_medium(a, ctr);
		return ("Medium / O(n*sqrt(n))");
	}
	if (strategy == COMPLEX)
	{
		sort_complex(a, ctr);
		return ("Complex / O(n*log(n))");
	}
	return (run_adaptive(a, ctr, dis));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_ctr	ctr;
	t_opts	opts;
	double	dis;
	char	*name;

	if (argc < 2)
		return (0);
	opts.strategy = ADAPTIVE;
	opts.bench = 0;
	a = parse_args(argc, argv, &opts);
	if (!a)
		return (0);
	assign_index(a);
	init_counter(&ctr);
	dis = disorder(a);
	name = sort_stack(&a, &ctr, opts.strategy, dis);
	if (opts.bench)
		bench(dis, &ctr, name);
	free_stack(&a);
	return (0);
}
