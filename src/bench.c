/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 13:17:46 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 13:28:03 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_complexity(t_strategy selected)
{
	if (selected == SIMPLE)
		ft_putstr_fd("O(n^2)", 2);
	else if (selected == MEDIUM)
		ft_putstr_fd("O(n√n)", 2);
	else if (selected == COMPLEX)
		ft_putstr_fd("O(n log n)", 2);
}

static void	print_strategy(t_strategy strategy, t_strategy selected)
{
	ft_putstr_fd("[bench] strategy: ", 2);
	if (strategy == ADAPTIVE)
	{
		ft_putstr_fd("Adaptive / ", 2);
		print_complexity(selected);
	}
	else if (strategy == SIMPLE)
		ft_putstr_fd("Simple / O(n^2)", 2);
	else if (strategy == MEDIUM)
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (strategy == COMPLEX)
		ft_putstr_fd("Complex / O(n log n)", 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_strategy strategy, t_strategy selected,
		double disorder, t_counters *c)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	put_percent(disorder);
	ft_putchar_fd('\n', 2);
	print_strategy(strategy, selected);
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(count_operations(c), 2);
	ft_putchar_fd('\n', 2);
	print_counters(c);
}

