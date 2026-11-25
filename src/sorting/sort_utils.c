/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:31:26 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/19 17:45:58 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

t_node	*find_max(t_stack *stack)
{
	t_node	*current;
	t_node	*max;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	max = current;
	while (current)
	{
		if (current->rank > max->rank)
			max = current;
		current = current->next;
	}
	return (max);
}

t_node	*find_min(t_stack *stack)
{
	t_node	*current;
	t_node	*min;

	if (!stack || !stack->top)
		return (NULL);
	current = stack->top;
	min = current;
	while (current)
	{
		if (current->rank < min->rank)
			min = current;
		current = current->next;
	}
	return (min);
}

void	move_top(t_stack *a, int p, int size, t_counters *c)
{
	int	i;

	i = 0;
	if (p <= size / 2)
	{
		while (i < p)
		{
			ra(a, c);
			i++;
		}
	}
	else
	{
		while (i < size - p)
		{
			rra(a, c);
			i++;
		}
	}
}

int	find_position(t_stack *stack, t_node *node)
{
	t_node	*current;
	int		position;

	if (!stack || !node)
		return (-1);
	current = stack->top;
	position = 0;
	while (current)
	{
		if (current == node)
			return (position);
		current = current->next;
		position++;
	}
	return (-1);
}
