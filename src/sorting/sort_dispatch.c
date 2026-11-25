/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_dispatch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 00:44:08 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 11:19:14 by melodrame        ###   ########.fr       */
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
		medium_sort(a, b, c);
	else if (opt->strategy == COMPLEX)
		radix_sort(a, b, c);
	else if (opt->strategy == ADAPTIVE)
<<<<<<< HEAD
		adaptuve_sort(a, b, c);
	
=======
		// adaptive selector, but radix for now so still works
		adaptive_sort(a, b, c);
>>>>>>> bd55deae9c6ae093adf2e10d60aaf416e9126be7
}

static void	adaptive_sort(t_stack *a, t_stack *b, t_counters *c)
{
	int		size;
	double	disorder;

	disorder = compute_disorder(a);
	if (a->size < 6)
		sort_small(a, b, c);
	else if (disorder < 0.2)
		simple_algo(a, b, c);
	else if (disorder >= 0.2 && disorder < 0.5 )
		medium_algo(a, b, c);
	else
		radix_sort(a, b, c);
}
