NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       input_processing.c \
       stack_ops.c \
       push_swap_utils.c \
       swap_fonctions.c \
       push_operations.c \
       rotate_fonctions.c \
       reverse_rotate_fonctions.c \
       sorting.c \
       radix.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re