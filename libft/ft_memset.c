/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:41:05 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 18:14:00 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *src, int c, size_t n)
{
	unsigned char	*csrc;
	unsigned char	cc;
	size_t			i;

	csrc = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		cc = (unsigned char )c;
		csrc[i] = cc;
		i++;
	}
	return (src);
}
