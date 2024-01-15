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
			push_chunks.c \
			push_a_cheapest.c \
			analyze_cost.c

NAME = push_swap

LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft
LDLIBS = $(LDFLAGS)

$(NAME): libft
	$(CC) $(CFLAGS) $(SOURCES) $(LIBFT_PATH) $(LDLIBS) -o $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Mark targets that don't correspond to file names
.PHONY: all re clean fclean libft