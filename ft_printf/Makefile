# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xinchong <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/11/22 17:23:59 by xinchong          #+#    #+#              #
#    Updated: 2026/11/22 17:41:29 by xinchong         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = ft_printf.c ft_p_hex.c ft_p_char.c \
ft_p_integer.c ft_p_pointer.c ft_p_string.c \
ft_p_unsigned.c \

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) *.out *gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
