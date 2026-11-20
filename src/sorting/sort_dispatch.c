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
		radix_sort(a, b, c);
	else if (opt->strategy == ADAPTIVE)
		// adaptive selector, but radix for now so still works
		radix_sort(a, b, c);
}
