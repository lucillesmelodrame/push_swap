NAME = push_swap.a

FLAGS = -Wall -Wextra -Werror

CC = cc

OBJECTS = $(SRCS:.c=.o)

SRCS = $(STACKDIR)stack_parse.c \
		$(STACKDIR)stack_llst.c \
		$(STACKDIR)stack_utils.c \
		# add more later

STACKDIR=stack/

LIBFTDIR=libft/
LIBFTA:=libft.a
LIBFT=$(LIBFTDIR)$(LIBFTA)

INCLUDE=includes $(LIBFTDIR) .

all: $(NAME)

$(LIBFT):
	make -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJECTS)
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
