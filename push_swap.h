/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:07:27 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/16 21:11:53 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef "PUSH_SWAP_H"
# define "PUSH_SWAP_H"

typedef struct s_node
{
	int	value;
	int	rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct	s_stack
{
	t_node	*top;
	t_node	*bottom;
	int	size;
}	t_stack;

typedef	struct	s_counters
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
}	t_counters;

#endif
