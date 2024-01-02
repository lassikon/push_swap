# Define compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Define source files for main library
SOURCES = push_swap.c \
			push_a.c \
			push_b.c \
			push_swap_utils.c \
			rotate.c \
			rev_rotate.c \
			sort_stack.c \
			big_sort.c \
			swap.c \
			calc_costs.c \
			debug.c

# Define library name
NAME = push_swap

# Rule to build the main library
$(NAME):
	$(CC) $(CFLAGS) $(SOURCES) -o $(NAME)

# Default target, builds the main library
all: $(NAME)

# Rule to clean and rebuild the library
re: fclean all

# Rule to clean up object files
clean:
	rm -f $(NAME)

# Rule to clean up object files AND library
fclean: clean

# Mark targets that don't correspond to file names
.PHONY: all re clean fclean