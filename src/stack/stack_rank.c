/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_rank.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 21:10:09 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 21:47:06 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	t_node	*x;
	t_node	*y;
	int		rank;

	x = a->top;
	while (x)
	{
		rank = 0;
		y = a->top;
		while (y)
		{
			if (y->value < x->value)
				rank++;
			y = y->next;
		}
		x->rank = rank;
		x = x->next;
	}
}
