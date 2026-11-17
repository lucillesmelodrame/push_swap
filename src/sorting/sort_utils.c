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

#include "../../push_swap.h"

t_node *find_max(t_stack *stack)
{
    t_node *max;
    t_node *i;

    if (!stack)
        return NULL;
    i = stack->top;
    max = i;
    while (i)
    {
        if (i->value > max->value)
            max = i;
        i = i->next;
    }
    return &(max->value);
}

int *find_min(t_stack *stack)
{
    t_node *min;
    t_node *i;

    if (!stack)
        return NULL;
    i = stack->top;
    min = i;
    while (i)
    {
        if (i->value < min->value)
            min = i;
        i = i->next;
    }
    return &(min->value);
}

void    move_top(t_stack *a, int p, int size, t_counters *c)
{
    int i;

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
