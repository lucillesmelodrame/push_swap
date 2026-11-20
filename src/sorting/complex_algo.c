/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 18:06:07 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/19 22:23:27 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"
/* number of bits needed to write the biggest rank (size - 1) */
static int	max_bits(t_stack *a)
{
	int	max_rank;
	int	bits;

	if (!a || a->size == 0)
		return (0);
	max_rank = a->size - 1;
	bits = 0;
	while ((max_rank >> bits) != 0)
		bits++;
	return (bits);
}

static void	radix_pass(t_stack *a, t_stack *b, t_counters *c, int bit)
{
	int	i;
	int	size;
	int	x;

	size = a->size;
	i = 0;
	while (i < size)
	{
		x = a->top->rank;
		if ((x >> bit) & 1)
			ra(a, c);
		else
			pb(a, b, c);
		i++;
	}
	while (b->top)
		pa(a, b, c);
}

void	radix_sort(t_stack *a, t_stack *b, t_counters *c)
{
	int	bit;
	int	bits;

	bits = max_bits(a);
	bit = 0;
	while (bit < bits)
	{
		radix_pass(a, b, c, bit);
		bit++;
	}
}
