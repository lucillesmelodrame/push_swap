/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 00:44:08 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 13:20:44 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static t_strategy	adaptive_sort(t_stack *a, t_stack *b, t_counters *c)
{
	double	disorder;

	disorder = compute_disorder(a);
	if (a->size < 6)
	{
		sort_small(a, b, c);
		return (SIMPLE);
	}
	else if (disorder < 0.2)
	{
		simple_algo(a, b, c);
		return (SIMPLE);
	}
	else if (disorder < 0.5)
	{
		medium_sort(a, b, c);
		return (MEDIUM);
	}
	radix_sort(a, b, c);
	return (COMPLEX);
}

t_strategy	run_sort(t_options *opt, t_stack *a, t_stack *b,
		t_counters *c)
{
	t_strategy	selected;

	selected = opt->strategy;
	if (is_sorted(a))
		return (selected);
	if (selected == ADAPTIVE)
		selected = adaptive_sort(a, b, c);
	else if (selected == SIMPLE)
		simple_algo(a, b, c);
	else if (selected == MEDIUM)
		medium_sort(a, b, c);
	else if (selected == COMPLEX)
		radix_sort(a, b, c);
	return (selected);
}
