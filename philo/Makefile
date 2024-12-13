NAME = philo
SRCS =  main.c \
	utils.c \
	input.c
OBJS = $(SRCS:.c=.o)

CC = cc
CFLAGS = -g -Wall -Wextra -Werror

# Default target
all: $(NAME)

# Build the executable
$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)


# Compile object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	rm -f $(OBJS)
# Clean all, including the executable
fclean: clean
	rm -f $(NAME)

# Rebuild the project
re: fclean all

.PHONY: all clean fclean re
