/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:18:21 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/19 16:18:51 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	reverse(t_stack *stack)
{
	t_node	*new_bottom;
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = first;
	while (last->next)
		last = last->next;
	new_bottom = last->prev;
	new_bottom->next = NULL;
	last->prev = NULL;
	last->next = first;
	first->prev = last;
	stack->top = last;
	stack->bottom = new_bottom;
}
//Rotate reverse by 1  , last node become first

void	rra(t_stack *a, t_counters *c)
{
	if (!a || !a->top || !a->top->next)
		return ;
	reverse(a);
	if (c)
	{
		c->rra++;
		write(1, "rra\n", 4);
	}
}
//rotate reverse stack a

void	rrb(t_stack *b, t_counters *c)
{
	if (!b || !b->top || !b->top->next)
		return ;
	reverse(b);
	if (c)
	{
		c->rrb++;
		write(1, "rrb\n", 4);
	}
}
//rotate reverse stack b

void	rrr(t_stack *a, t_stack *b, t_counters *c)
{
	int	run;

	run = 0;
	if (a && a->top && a->top->next)
	{
		reverse(a);
		run += 1;
	}
	if (b && b->top && b->top->next)
	{
		reverse(b);
		run += 1;
	}
	if (c && run > 0)
	{
		c->rrr++;
		write(1, "rrr\n", 4);
	}
}
