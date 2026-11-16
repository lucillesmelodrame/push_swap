/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:28:35 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/16 15:18:02 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	p_top(t_stack *from, t_stack *to)
{
	t_node	*node;
	t_node	*new_from_top;
	t_node	*old_to_top;

	node = from->top;
	new_from_top = node->next;
	if (new_from_top != NULL)
		new_from_top->prev = NULL;
	from->top = new_from_top;
	old_to_top = to->top;
	if (old_to_top != NULL)
		old_to_top->prev = node;
	node->next = old_to_top;
	to->top = node;
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
