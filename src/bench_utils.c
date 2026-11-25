/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:18:37 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 13:28:42 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_percent(double d)
{
	long	hundredths;
	int		whole;
	int		frac;

	hundredths = (long)(d * 10000 + 0.5);
	whole = hundredths / 100;
	frac = hundredths % 100;
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(frac, 2);
	ft_putchar_fd('%', 2);
}

int	count_operations(t_counters *c)
{
	int	total;

	total = 0;
	if (!c)
		return (0);
	total += c->sa;
	total += c->sb;
	total += c->ss;
	total += c->pa;
	total += c->pb;
	total += c->ra;
	total += c->rb;
	total += c->rr;
	total += c->rra;
	total += c->rrb;
	total += c->rrr;
	return (total);
}

static void	print_counter(char *name, int count)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(": ", 2);
	ft_putnbr_fd(count, 2);
	ft_putstr_fd("  ", 2);
}

void	print_counters(t_counters *c)
{
	if (!c)
		return ;
	ft_putstr_fd("[bench] ", 2);
	print_counter("sa", c->sa);
	print_counter("sb", c->sb);
	print_counter("ss", c->ss);
	print_counter("pa", c->pa);
	print_counter("pb", c->pb);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	print_counter("ra", c->ra);
	print_counter("rb", c->rb);
	print_counter("rr", c->rr);
	print_counter("rra", c->rra);
	print_counter("rrb", c->rrb);
	print_counter("rrr", c->rrr);
	ft_putchar_fd('\n', 2);
}
