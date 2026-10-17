NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror

SRCS	= main.c \
		  ft_split.c \
		  parse.c \
		  parse_utils.c \
		  stack_utils.c \
		  op_push.c \
		  op_reverse.c \
		  op_rotate.c \
		  op_swap.c \
		  sort_small.c \
		  sort_utils.c

OBJS	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re