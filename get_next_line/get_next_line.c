/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/26 19:13:56 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/12 03:37:23 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*n1;

	stash = read_to_stash(fd, stash);
	if (!stash || stash[0] == '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	n1 = find_newline(stash);
	line = stash;
	if (!n1)
		n1 = stash + my_strlen(stash) - 1;
	stash = my_strdup(n1 + 1);
	if (!stash)
	{
		free(line);
		return (NULL);
	}
	n1[1] = '\0';
	return (line);
}
