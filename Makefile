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

BONUS_DIR = bonus

BONUS_SOURCES = $(BONUS_DIR)/checker.c \
				$(BONUS_DIR)/checker_push.c \
				$(BONUS_DIR)/checker_swap.c \
				$(BONUS_DIR)/checker_rotate.c \
				$(BONUS_DIR)/checker_rev_rotate.c \

NAME = push_swap

BONUS_NAME = checker

LIBFT_DIR = libft
LIBFT_PATH = $(LIBFT_DIR)/libft.a
LDFLAGS = -L$(LIBFT_DIR) -lft

$(NAME): libft
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(NAME)

libft:
	@$(MAKE) -C $(LIBFT_DIR)

all: $(NAME)

bonus: $(CC) $(CFLAGS) $(BONUS_SOURCES) -o $(BONUS_NAME)

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean

# Mark targets that don't correspond to file names
.PHONY: all re clean fclean libft