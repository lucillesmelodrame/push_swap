/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_integer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:03:30 by xinchong          #+#    #+#             */
/*   Updated: 2026/10/16 17:37:02 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_p_integer(int nbr)
{
	size_t	int_len;

	int_len = 0;
	if (nbr == -2147483648)
	{
		int_len += ft_p_string("-2147483648");
		return (int_len);
	}
	if (nbr < 0)
	{
		int_len += ft_p_char('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		int_len += ft_p_integer(nbr / 10);
	int_len += ft_p_char((nbr % 10) + '0');
	return (int_len);
}
