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

static t_strategy	adaptive_sort(t_options *opt, t_stack *a, t_stack *b,
		t_counters *c)
{
	if (a->size < 6)
	{
		sort_small(a, b, c);
		return (SIMPLE);
	}
	if (opt->disorder < 0.2)
	{
		simple_algo(a, b, c);
		return (SIMPLE);
	}
	if (opt->disorder < 0.5)
	{
		medium_sort(a, b, c);
		return (MEDIUM);
	}
	radix_sort(a, b, c);
	return (COMPLEX);
}

void	run_sort(t_options *opt, t_stack *a, t_stack *b, t_counters *c)
{
	opt->selected = opt->strategy;
	if (opt->strategy == ADAPTIVE)
		opt->selected = SIMPLE;
	if (is_sorted(a))
		return ;
	if (opt->strategy == ADAPTIVE)
		opt->selected = adaptive_sort(opt, a, b, c);
	else if (opt->strategy == SIMPLE)
		simple_algo(a, b, c);
	else if (opt->strategy == MEDIUM)
		medium_sort(a, b, c);
	else
		radix_sort(a, b, c);
}
