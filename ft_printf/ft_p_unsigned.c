/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_unsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:03:49 by xinchong          #+#    #+#             */
/*   Updated: 2026/10/16 17:48:17 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_p_unsigned(unsigned int nbr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr >= 10)
		nbr_len += ft_p_unsigned(nbr / 10);
	nbr_len += ft_p_char((nbr % 10) + '0');
	return (nbr_len);
}
