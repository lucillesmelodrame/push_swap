/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_algo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 19:46:30 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/19 15:49:56 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

//selection sort
void simple_algo(t_stack *a, t_stack *b, t_counters *c)
{
	t_node	*min;
    int size;
    int p;

    size = a->size;
    while (size > 0)
  {
        min = find_min(a);
		position = find_position(a, min);
        move_top(a, position, size, c);
        pb(a, b, c);
        size--;
    }//finding the min and move top of stack a push it
    while (b->size > 0)
        pa(a, b, c);
}//push back all to a
