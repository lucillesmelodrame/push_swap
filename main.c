/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:03:30 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 13:20:08 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_stack *s)
{
	s->top = NULL;
	s->bottom = NULL;
	s->size = 0;
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_counters	c;
	t_options	opt;
	t_strategy	selected;
	double		disorder;
	int			used;

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
	disorder = compute_disorder(&a);
	selected = run_sort(&opt, &a, &b, &c);
	if (opt.bench)
		print_bench(opt.strategy, selected, disorder, &c);
	ft_llstclear(&a);
	ft_llstclear(&b);
	return (0);
}
