NAME	= push_swap

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
RM		= rm -f

SRCS	= main.c \
		  bench.c \
		  ft_split.c \
		  parse.c \
		  parse_utils.c \
		  stack_utils.c \
		  op_push.c \
		  op_reverse.c \
		  op_rotate.c \
		  op_swap.c \
		  sort_simple.c \
		  sort_medium.c \
		  sort_complex.c \
		  sort_utils.c

OBJS	= $(SRCS:.c=.o)

HEADER	= push_swap.h

all: $(NAME)

$(OBJS): $(HEADER)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re