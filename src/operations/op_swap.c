/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:54:09 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/19 15:59:57 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

static void	s_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	if (!stack || stack->size < 2)
		return ;
	first = stack->top;
	second = first->next;
	temp = second->next;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	first->next = temp;
	if (temp)
		temp->prev = first;
	else
		stack->bottom = first;
	stack->top = second;
}
//swap the 2 node by changing the prev and next node
//last change the pointer of the stack to the current top node

void	sa(t_stack *a, t_counters *c)
{
	if (!a || !a->top || !a->top->next)
		return ;
	s_top(a);
	if (c)
	{
		c->sa++;
		write(1, "sa\n", 3);
	}
}
//swap stack a top 2
//should we add a print check?

void	sb(t_stack *b, t_counters *c)
{
	if (!b ||!b->top || !b->top->next)
		return ;
	s_top(b);
	if (c)
	{
		c->sb++;
		write(1, "sb\n", 3);
	}
}
//swap stack b top 2

void	ss(t_stack *a, t_stack *b, t_counters *c)
{
	int	run;

	run = 0;
	if (a && a->top && a->top->next)
	{
		s_top(a);
		run += 1;
	}
	if (a && b->top && b->top->next)
	{
		s_top(b);
		run += 1;
	}
	if (c && run > 0)
	{
		c->ss++;
		write(1, "ss\n", 3);
	}
}
//swap both stack a and b top 2
