/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:23:42 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/12 03:36:59 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	my_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*my_strjoin(char const *s1, char const *s2, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = malloc((my_strlen(s1) + len + 1) * sizeof(char));
	if (!str)
	{
		free((void *)s1);
		return (NULL);
	}
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len)
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	free((void *)s1);
	return (str);
}

char	*find_newline(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if ((unsigned char)str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*read_to_stash(int fd, char *stash)
{
	ssize_t	ret;
	char	*buf;

	buf = malloc((BUFFER_SIZE + 1) * sizeof(char));
	ret = 1;
	if (!buf)
	{
		free(stash);
		return (NULL);
	}
	while (ret > 0 && !find_newline(stash))
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret >= 0)
			stash = my_strjoin(stash, buf, ret);
		if (ret == -1 || !stash)
		{
			free(buf);
			free(stash);
			return (NULL);
		}
	}
	free(buf);
	return (stash);
}

char	*my_strdup(const char *str)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = malloc((my_strlen(str) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (str[i])
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
