/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 04:55:52 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/24 15:47:50 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	int_sqrt(int n)
{
	int	i;

	i = 0;
	while ((long)(i + 1) * (i + 1) <= n)
		i++;
	return (i);
}

static int	chunk_size(int n)
{
	int	k;

	k = int_sqrt(n) / 2;
	if (k == 0)
		k = 1;
	return ((n + k - 1) / k);
}

static void	push_chunk(t_stack *a, t_stack *b, t_counters *c, int chunk)
{
	int	size;
	int	passes;
	int	i;

	size = chunk_size(a->size + b->size);
	passes = a->size;
	i = 0;
	while (i < passes)
	{
		if ((a->top->rank / size) == chunk)
			pb(a, b, c);
		else
			ra(a, c);
		i++;
	}
}

static void	max_to_top(t_stack *b, t_counters *c)
{
	t_node	*max;
	int		pos;

	max = find_max(b);
	pos = find_position(b, max);
	if (pos <= (b->size / 2))
	{
		while (pos--)
			rb(b, c);
	}
	else
	{
		pos = b->size - pos;
		while (pos--)
			rrb(b, c);
	}
}

void	medium_sort(t_stack *a, t_stack *b, t_counters *c)
{
	int	chunk;

	chunk = 0;
	while (a->size > 0)
	{
		push_chunk(a, b, c, chunk);
		chunk++;
	}
	while (b->size > 0)
	{
		max_to_top(b, c);
		pa(a, b, c);
	}
}
