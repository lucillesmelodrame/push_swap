NAME = push_swap

CC = cc
FLAGS = -Wall -Wextra -Werror

ODIR = objs/
OBJS = $(SRCS:$(SRCDIR)%.c=$(ODIR)%.o) \
		$(ODIR)main.o

SRCS = $(STACKDIR)stack_parse.c \
		$(STACKDIR)stack_llst.c \
		$(STACKDIR)stack_utils.c \
		$(STACKDIR)stack_disorder.c
		# add more later

HEADER = push_swap.h

SRCDIR = src/
STACKDIR = $(SRCDIR)stack/

LIBFTDIR = libft/
LIBFT = $(LIBFTDIR)libft.a
INCLUDE = $(LIBFTDIR) .

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(FLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(ODIR)%.o: $(SRCDIR)%.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE:%=-I%) -c $< -o $@

$(ODIR)%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(INCLUDE:%=-I%) -c $< -o $@

clean:
	rm -rf $(ODIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
