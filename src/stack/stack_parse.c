/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sonfong <sonfong@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:07:41 by sonfong           #+#    #+#             */
/*   Updated: 2026/10/24 04:00:06 by melodrame        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../push_swap.h"

int	is_valid_int(char *str, int *out)
{
	size_t	i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i++] - '0');
		if (res * sign < INT_MIN || res * sign > INT_MAX)
			return (1);
	}
	if (str[i])
		return (1);
	*out = (int)(res * sign);
	return (0);
}

int	has_duplicates(t_stack *stack)
{
	t_node	*a;
	t_node	*b;

	a = stack->top;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->value == b->value)
				return (1);
			b = b->next;
		}
		a = a->next;
	}
	return (0);
}

static int	add_tokens(t_stack *a, char **tokens)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (!tokens || !tokens[0])
		return (1);
	while (tokens[i])
	{
		if (is_valid_int(tokens[i], &num))
			return (1);
		if (add_bottom(a, num))
			return (1);
		i++;
	}
	return (0);
}

int	build_stack(t_stack *a, char **args)
{
	char	**tokens;
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (args[i])
	{
		tokens = ft_split(args[i], ' ');
		ret = add_tokens(a, tokens);
		free_split(tokens);
		if (ret)
			return (1);
		i++;
	}
	if (has_duplicates(a))
		return (1);
	return (0);
}
