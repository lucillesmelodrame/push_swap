/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:11:02 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 18:13:52 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*cdest;
	char	*csrc;
	size_t	i;

	cdest = (char *)dest;
	csrc = (char *)src;
	i = 0;
	if (!dest && !src)
		return (0);
	else if (dest <= src)
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	else if (dest > src)
	{
		while (n--)
			cdest[n] = csrc[n];
	}
	return (dest);
}
