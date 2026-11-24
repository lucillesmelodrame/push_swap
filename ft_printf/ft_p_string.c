/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_string.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 15:57:36 by xinchong          #+#    #+#             */
/*   Updated: 2026/10/16 17:34:16 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_p_string(char *str)
{
	size_t	str_len;

	str_len = 0;
	if (str == NULL)
	{
		str_len += ft_p_string("(null)");
		return (str_len);
	}
	while (str[str_len] != '\0')
		str_len += ft_p_char(str[str_len]);
	return (str_len);
}
