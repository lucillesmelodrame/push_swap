/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 16:02:36 by sonfong           #+#    #+#             */
/*   Updated: 2026/09/02 18:32:40 by sonfong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!find || !find[0])
		return ((char *)src);
	while (src[i] && i < n)
	{
		while (src[i + j] == find[j] && src[i + j] && i + j < n)
		{
			j++;
			if (find[j] == 0)
				return ((char *)src + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
