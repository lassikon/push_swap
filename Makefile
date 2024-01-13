CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = push_swap.c \
			push_a.c \
			push_b.c \
			rotate.c \
			rev_rotate.c \
			sort_stack.c \
			big_sort.c \
			swap.c \
			calc_costs.c \
			init_stacks.c \
			parsing.c \
			check_sorted.c \
			debug.c

NAME = push_swap

$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -g -o $(NAME)

all: $(NAME)

re: fclean all

clean:
	rm -f $(NAME)

fclean: clean

# Mark targets that don't correspond to file names
.PHONY: all re clean fclean