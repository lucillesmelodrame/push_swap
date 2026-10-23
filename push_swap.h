/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 21:07:27 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 04:49:47 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	int		size;
}	t_stack;

typedef struct s_counters
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

void	sa(t_stack *a, t_counters *c);
void	sb(t_stack *b, t_counters *c);
void	ss(t_stack *a, t_stack *b, t_counters *c);
void	pa(t_stack *a, t_stack *b, t_counters *c);
void	pb(t_stack *a, t_stack *b, t_counters *c);
void	ra(t_stack *a, t_counters *c);
void	rb(t_stack *b, t_counters *c);
void	rr(t_stack *a, t_stack *b, t_counters *c);
void	rra(t_stack *a, t_counters *c);
void	rrb(t_stack *b, t_counters *c);
void	rrr(t_stack *a, t_stack *b, t_counters *c);

int		is_valid_int(char *str, int *out);
int		has_duplicates(t_stack *stack);
int		add_bottom(t_stack *stack, int value);
void	ft_llstclear(t_stack *stack);
int		build_stack(t_stack *a, char **args);
void	free_split(char **arr);
double	compute_disorder(t_stack *a);
#endif
