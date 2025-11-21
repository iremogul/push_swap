NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = input_processing.c \
       split.c \
       reverse_rotate_fonctions.c \
       push_swap_utils.c \
       stack_ops.c \
       rotate_fonctions.c \
       swap_fonctions.c \
       main.c

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