NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = # add later

LIBFTDIR=libft/
LIBFTA:=libft.a
LIBFT=$(LIBFTDIR)$(LIBFTA)

INCLUDE=includes $(LIBFTDIR) .

all: $(NAME)

$(NAME): $(OBJECTS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDE:%=-I%) -c $< -o $@

clean:
	rm -f $(OBJECTS)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
