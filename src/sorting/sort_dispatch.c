/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 00:44:08 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/20 00:56:48 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	adaptive_sort(t_stack *a, t_stack *b, t_counters *c);

void	run_sort(t_options *opt, t_stack *a, t_stack *b, t_counters *c)
{
	if (is_sorted(a))
		return ;
	if (opt->strategy == SIMPLE)
		simple_algo(a, b, c);
	else if (opt->strategy == MEDIUM)
		// medium sort, temporarily use radix
		radix_sort(a, b, c);
	else if (opt->strategy == COMPLEX)
		complex_sort(a, b, c);
	else if (opt->strategy == ADAPTIVE)
		// adaptive selector, but radix for now so still works
	
}

static void	adaptive_sort(t_stack *a, t_stack *b, t_counters *c)
{
	int	size;
	double	disorder;

	size = ft_llstsize(a->top);
	disorder = compute_disorder(a);
	if (disorder < 0.2 || size < 6)
		simple_algo(a,b,c);
	else if (disorder >= 0.2 & disorder < 0.5 )
		radix_sort(a, b, c);
	else
		complex_sort(a, b, c);
}

