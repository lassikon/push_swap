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
LDFLAGS = -L$(LIBFT_DIR) -lft

LIBFT_MARKER = .libft

$(LIBFT_MARKER):
	@$(MAKE) -C $(LIBFT_DIR) > /dev/null
	@echo "Built libft"
	touch $(LIBFT_MARKER) > /dev/null

$(NAME): $(LIBFT_MARKER)
	$(CC) $(CFLAGS) $(SOURCES) $(LDFLAGS) -o $(NAME)
	@echo "Built push_swap"

all: $(NAME)

bonus: $(LIBFT_MARKER)
	$(CC) $(CFLAGS) $(BONUS_SOURCES) $(LDFLAGS) -o $(BONUS_NAME)
	@echo "Built checker"

re: fclean all

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean > /dev/null
	@echo "Removed object files"

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean > /dev/null
	rm -f $(LIBFT_MARKER)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)
	@echo "Removed executables"

.PHONY: all re clean fclean bonus