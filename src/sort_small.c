/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 16:01:40 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 09:08:20 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *a, t_counters *c)
{
	t_node	*current;
	t_node	*max;

	if (!a || a->size != 3)
		return ;
	current = a->top;
	max = find_max(a);
	if (current == max)
		ra(a, c);
	else if (current->next == max)
		rra(a, c);
	if (a->top->value > a->top->next->value)
		sa(a, c);
}

static void	push_min(t_stack *a, t_stack *b, t_counters *c)
{
	int	p;

	p = find_position(a, find_min(a));
	move_top(a, p, a->size, c);
	pb(a, b, c);
}

void	sort_small(t_stack *a, t_stack *b, t_counters *c)
{
	if (a->size == 2 && a->top->value > a->top->next->value)
		sa(a, c);
	else if (a->size == 3)
		sort_three(a, c);
	else if (a->size == 4)
	{
		push_min(a, b, c);
		sort_three(a, c);
		pa(a, b, c);
	}
	else if (a->size == 5)
	{
		push_min(a, b, c);
		push_min(a, b, c);
		sort_three(a, c);
		pa(a, b, c);
		pa(a, b, c);
	}
}
