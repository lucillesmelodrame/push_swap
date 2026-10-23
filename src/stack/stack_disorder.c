/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_disorder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 04:13:53 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 04:30:13 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

double	compute_disorder(t_stack *a)
{
	t_node	*x;
	t_node	*y;
	long	mistakes;
	long	total;

	mistakes = 0;
	total = 0;
	x = a->top;
	while (x)
	{
		y = x->next;
		while (y)
		{
			total++;
			if (x->value > y->value)
				mistakes++;
			y = y->next;
		}
	x = x->next;
	}
	if (total == 0)
		return (0);
	return ((double)mistakes / total);
}
