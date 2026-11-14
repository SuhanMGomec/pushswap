/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 19:33:09 by sgomec            #+#    #+#             */
/*   Updated: 2026/11/14 19:43:08 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int get_max_bits(int size)
{
	int	max;
	int	bits;
	
	max = size - 1;
	bits = 0;
	while (max)
	{
		max >>= 1;
		bits++;
	}
	return (bits);	
}

static void	radix_pass(t_stack **a, t_stack **b, int bit, t_ctr *ctr)