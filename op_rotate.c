/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 14:16:35 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/16 15:28:46 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack)
{
	t_node	*new_top;
	t_node	*first;
	t_node	*last;

	first = stack->top;
	last = first;
	while (last->next)
		last = last->next;
	new_top = first->next;
	if (new_top != NULL)
		new_top->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	stack->top = new_top;
	stack->bottom = first;
}
//Rotate by 1 , 1 node become last

void	ra(t_stack *a, t_counters *c)
{
	if (!a || !a->top || !a->top->next)
		return ;
	rotate(a);
	if (c)
	{
		c->ra++;
		write(1, "ra\n", 3);
	}
}
//rotate stack a

void	rb(t_stack *b, t_counters *c)
{
	if (!b || !b->top || !b->top->next)
		return ;
	rotate(b);
	if (c)
	{
		c->rb++;
		write(1, "rb\n", 3);
	}
}
//rotate stack b

void	rr(t_stack *a, t_stack *b, t_counters *c)
{
	int	run;

	run = 0;
	if (a && a->top && a->top->next)
	{
		rotate(a);
		run += 1;
	}
	if (b && b->top && b->top->next)
	{
		rotate(b);
		run += 1;
	}
	if (c && run == 2)
	{
		c->rr++;
		write(1, "rr\n", 3);
	}
}
//rotate both stack a and b
