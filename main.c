/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 05:03:30 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 05:16:21 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;

	if (argc <= 1)
		return (0);
	a.top = NULL;
	a.bottom = NULL;
	a.size = 0;
	if (build_stack(&a, argv + 1))
	{
		ft_putstr_fd("Error\n", 2);
		ft_llstclear(&a);
		return (1);
	}
	ft_llstclear(&a);
	return (0);
}
