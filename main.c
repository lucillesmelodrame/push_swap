/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:03:30 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/19 17:29:48 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

int		main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_counters	c;
	t_options	opt;
	int			used;

	used = 0;
	if (argc <= 1)
		return (0);
	init_stack(&a);
	used = parse_options(argv + 1, &opt);
	if (build_stack(&a, (argv + 1 + used)))
	{
		ft_putstr_fd("Error\n", 2);
		ft_llstclear(&a);
		return (1);
	}
	init_stack(&b);
	ft_bzero(&c, sizeof(c));
	assign_ranks(&a);
	if (opt.strategy == SIMPLE)
		simple_algo(&a, &b, &c);
	ft_llstclear(&a);
	return (0);
}
