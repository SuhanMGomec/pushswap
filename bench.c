/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgomec <sgomec@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 11:46:00 by gucakmak          #+#    #+#             */
/*   Updated: 2026/11/14 12:05:59 by sgomec           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_counter(t_ctr	*ctr)
{
	ctr->sa = 0;
	ctr->sb = 0;
	ctr->ss = 0;
	ctr->ra = 0;
	ctr->rb = 0;
	ctr->rr = 0;
	ctr->rra = 0;
	ctr->rrb = 0;
	ctr->rrr = 0;
	ctr->pa = 0;
	ctr->pb = 0;
}