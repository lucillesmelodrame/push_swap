/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 17:31:26 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/16 17:31:55 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node *find_max(t_stack *stack)
{
    t_node *max_node;
    t_node *current;

    if (!stack)
        return NULL;
    current = stack->top;
    max_node = current;
    while (current)
    {
        if (current->value > max_node->value)
            max_node = current;
        current = current->next;
    }
    return max_node;
}

t_node *find_min(t_stack *stack)
{
    t_node *min_node;
    t_node *current;

    if (!stack)
        return NULL;
    current = stack->top;
    min_node = current;
    while (current)
    {
        if (current->value < min_node->value)
            min_node = current;
        current = current->next;
    }
    return min_node;
}

void    push_rank_to_b(t_stack *a, t_stack *b, int rank, t_counters *c)
{
    
}