/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 16:22:23 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 21:54:30 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	is_flag(char *arg, char *name)
{
	if (ft_strncmp(arg, name, ft_strlen(name) + 1) == 0)
		return (1);
	return (0);
}

int	parse_options(char **args, t_options *opt)
{
	int	i;

	opt->strategy = ADAPTIVE;
	opt->bench = 0;
	i = 0;
	while (args[i])
	{
		if (is_flag(args[i], "--simple"))
			opt->strategy = SIMPLE;
		else if (is_flag(args[i], "--medium"))
			opt->strategy = MEDIUM;
		else if (is_flag(args[i], "--complex"))
			opt->strategy = COMPLEX;
		else if (is_flag(args[i], "--adaptive"))
			opt->strategy = ADAPTIVE;
		else if (is_flag(args[i], "--bench"))
			opt->bench = 1;
		else
			return (i);
		i++;
	}
	return (i);
}
