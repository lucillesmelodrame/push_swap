/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 16:42:20 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/16 16:43:57 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void sort_three(t_stack *a, t_counters *c);
static void sort_four_five(t_stack *a, t_stack *b, t_counters *c);
//not sure to use void or int
void sort_small(t_stack *a, t_stack *b, t_counters *c)
{
    if (a->size == 2)
    {
        if (a->top->value > a->top->next->value)
            sa(a, c);
    }
    else if (a->size == 3)
        sort_three(a, c);
    else if (a->size == 4 || a->size == 5)
        sort_four_five(a, b, c);
}

static void sort_three(t_stack *a, t_counters *c)
{
    t_node *current;
    t_node *max_node;

    if (!a || !a->size)
        return;
    current = a->top;
    max_node = find_max(a);
    if (current == max_node)
        ra(a, c);
    else if (current->next == max_node)
        rra(a, c);
    if((current->value > current->next->value))
        sa(a, c);
}

static void sort_four_five(t_stack *a, t_stack *b, t_counters *c)
{
    

}