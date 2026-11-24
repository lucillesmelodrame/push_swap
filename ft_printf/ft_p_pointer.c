/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_pointer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:02:55 by xinchong          #+#    #+#             */
/*   Updated: 2026/10/16 17:45:23 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_p_pointer(void *ptr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (ptr == NULL)
	{
		nbr_len += write(1, "(nil)", 5);
		return (nbr_len);
	}
	nbr_len += ft_p_string("0x");
	nbr_len += ft_p_hex((size_t)ptr, "0123456789abcdef");
	return (nbr_len);
}
