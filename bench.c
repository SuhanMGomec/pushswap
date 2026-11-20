/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:53:03 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/20 16:53:06 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i] != '\0')
		i++;
	write(fd, s, i);
}

static void	ft_putnbr_fd(int n, int fd)
{
	if (n < 10)
	{
		n = n % 10 + '0';
		write(fd, &n, 1);
	}
	else
	{
		ft_putnbr_fd(n / 10, 2);
		ft_putnbr_fd(n % 10, 2);
	}
}

static void	print_ops(char *a, int op)
{
	ft_putstr_fd(a, 2);
	ft_putnbr_fd(op, 2);
	write(2, "  ", 2);
}

static void	print_disorder(double disorder)
{
	int	i;

	i = disorder * 10000 + 0.5;
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(i / 100, 2);
	write(2, ".", 1);
	if (i % 100 < 10)
		write(2, "0", 1);
	ft_putnbr_fd(i % 100, 2);
	write(2, "%", 1);
}

void	bench(double disorder, t_ctr *ctr, char *strategy)
{
	int	total;

	print_disorder(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd(strategy, 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	total = ctr->ra + ctr->rb + ctr->rr + ctr->rra + ctr->rrb + ctr->rrr
		+ ctr->sa + ctr->sb + ctr->ss + ctr->pa + ctr->pb;
	ft_putnbr_fd(total, 2);
	write(2, "\n", 1);
	print_ops("[bench] sa:  ", ctr->sa);
	print_ops("sb:  ", ctr->sb);
	print_ops("ss:  ", ctr->ss);
	print_ops("pa:  ", ctr->pa);
	print_ops("pb:  ", ctr->pb);
	write(2, "\n", 1);
	print_ops("[bench] ra:  ", ctr->ra);
	print_ops("rb:  ", ctr->rb);
	print_ops("rr:  ", ctr->rr);
	print_ops("rra:  ", ctr->rra);
	print_ops("rrb:  ", ctr->rrb);
	print_ops("rrr:  ", ctr->rrr);
	write(2, "\n", 1);
}
