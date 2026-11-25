/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:04:26 by xinchong          #+#    #+#             */
/*   Updated: 2026/11/22 17:59:50 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*Not just made for hex base16, 
can be used for any base since there is not fix base.*/
#include "ft_printf.h"

static size_t	ft_strlen(const char *str)
{
	size_t	str_len;

	str_len = 0;
	while (str[str_len] != '\0')
		str_len++;
	return (str_len);
}

static int	ft_is_valid_base(const char *base)
{
	int	i;
	int	j;

	if (ft_strlen(base) < 2)
		return (0);
	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || \
base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

size_t	ft_p_hex(unsigned long nbr, const char *base)
{
	size_t	nbr_len;
	size_t	base_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (!ft_is_valid_base(base))
		return (0);
	if (nbr >= base_len)
		nbr_len += ft_p_hex(nbr / base_len, base);
	nbr_len += ft_p_char(base[nbr % base_len]);
	return (nbr_len);
}
