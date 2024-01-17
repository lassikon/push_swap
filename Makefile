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

BONUS_SOURCES = checker.c \
				push_a.c \
				push_b.c \
				rotate.c \
				rev_rotate.c \
				swap.c \
				init_stacks.c \
				parsing.c \


NAME = push_swap
HEADER = push_swap.h
BONUS_NAME = checker

LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

$(NAME): libft
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(NAME)

$(BONUS_NAME):
	$(CC) -g $(CFLAGS) $(BONUS_SOURCES) $(LDFLAGS) -o $(BONUS_NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(BONUS_NAME)

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Mark targets that don't correspond to file names
.PHONY: all re clean fclean libft