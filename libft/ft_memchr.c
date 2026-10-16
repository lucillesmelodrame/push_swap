/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 16:59:33 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 18:13:32 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	unsigned char	*csrc;
	size_t			i;

	csrc = (unsigned char *)src;
	i = 0;
	while (n--)
	{
		if ((unsigned char)c == csrc[i])
			return (&csrc[i]);
		i++;
	}
	return (NULL);
}
