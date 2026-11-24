/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xinchong <xinchong@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:25:50 by xinchong          #+#    #+#             */
/*   Updated: 2026/10/16 17:31:29 by xinchong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h> 
// System calls like write.
# include <stdarg.h> 
// Variable arguments like va_start, va_arg, va_copy,va_end.
# include <stdlib.h> 
// Memory allocation like malloc, free and size_t.
# include <limits.h> 
// MIN and MAX to check int overflows.
# include <stdio.h> 
// Printf testing.

int		ft_printf(const char *format, ...);
size_t	ft_p_char(char c);
size_t	ft_p_string(char *str);
size_t	ft_p_pointer(void *ptr);
size_t	ft_p_integer(int nbr);
size_t	ft_p_unsigned(unsigned int nbr);
size_t	ft_p_hex(unsigned long nbr, const char *base);

#endif
