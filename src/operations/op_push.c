/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:28:35 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/19 15:54:15 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	p_top(t_stack *from, t_stack *to)
{
	t_node	*node;

	node = from->top;
	//remove node from source stack
	from->top = node->next;
	if (from->top)
		from->top->prev = NULL;
	else
		from->bottom = NULL;
	from->size--;
	//prepare node for dest stack
	node->prev = NULL;
	node->next = to->top;
	//insert node at dest top
	if (to->top)
		to->top->prev = node;
	else
		to->bottom = node;
	to->top = node;
	to->size++;
}
//push the top node from stack 'from' to stack 'to'

void	pa(t_stack *a, t_stack *b, t_counters *c)
{
	if (!a || !b || !b->top)
		return ;
	p_top(b, a);
	if (c)
	{
		c->pa++;
		write(1, "pa\n", 3);
	}
}
//push the top node from stack b to stack a

void	pb(t_stack *a, t_stack *b, t_counters *c)
{
	if (!a || !b || !a->top)
		return ;
	p_top(a, b);
	if (c)
	{
		c->pb++;
		write(1, "pb\n", 3);
	}
}
//push the top node from stack a to stack b
