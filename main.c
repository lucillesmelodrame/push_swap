/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:03:30 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 21:45:45 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		a;
	int			used;
	t_options	opt;

	used = 0;
	if (argc <= 1)
		return (0);
	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	used = parse_options(argv + 1, &opt);
	if (build_stack(&a, (argv + 1 + used)))
	{
		ft_putstr_fd("Error\n", 2);
		ft_llstclear(&a);
		return (1);
	}
	assign_ranks(&a);
	ft_llstclear(&a);
	return (0);
}
