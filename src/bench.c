/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:19:41 by sonfong           #+#    #+#             */
/*   Updated: 2026/11/25 11:57:09 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_percent(double d)
{
	long	hundreths;
	int		whole;
	int		frac;

	hundredths = (long)(d * 10000 + 0.5);
	whole = hundreths / 100;
	frac = hundreths % 100;
	ft_putnbr_fd(whole, 2);
	ft_putchar_fd('.', 2);
	if (frac < 10)
		ft_putnbr_fd(0, 2);
	ft_putnbr_fd(frac, 2);
	ft_putchar_fd('%', 2);
}
