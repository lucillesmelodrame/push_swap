/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 19:46:30 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/17 19:49:18 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../push_swap.h"

//selection sort
t_node *find_min(t_stack *stack);
void move_top(t_stack *a, int p, int size, t_counters *c);

void simple_algo(t_stack *a, t_stack *b, t_counters *c)
{
    int size;
    int p;

    size = a->size;
    while (size > 0)
    {
        p = find_min(a);
        move_top(a, p, size, c);
        pb(a, b, c);
        size--;
    }//finding the min and move top of stack a push it
    while (b != NULL)
        pa(a, b, c);
}//push back all to a