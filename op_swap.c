/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 11:54:09 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/16 13:10:58 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	s_top(t_stack *stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*temp;

	if (stack->size < 2)
		return (0);
	first = stack->top;
	second = first->next;
	temp = second->next;
	first->next = temp;
	first->prev = second;
	second->next = first;
	second->prev = NULL;
	if (temp != NULL)
		temp->prev = first;
	stack->top = second;
}
//swap the 2 node by changing the prev and next node
//last change the pointer of the stack to the current top node

void	sa(t_stack *a, t_counters *counters)
{
	if (!a->top || !a->top->next)
		return (0);
	s_top(a);
	if (counters)
	{
		counters->sa++;
		write(1, "sa\n", 3);
	}
}
//swap stack a top 2
//should we add a print check?

void	sb(t_stack *b, t_counters *counters)
{
	if (!b->top || !b->top->next)
		return (0);
	s_top(b);
	if (counters)
		counters->sb++;
	write(1, "sb\n", 3);
}
//swap stack b top 2
