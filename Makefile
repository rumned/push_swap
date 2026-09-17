NAME			= push_swap
BONUS_NAME		= checker

CC			= cc
CFLAGS			= -Wall -Wextra -Werror

RM			= rm -f

MAIN_PROG		= valid.c \
			  parse_flags.c \
			  build_args.c \
			  parse_and_index.c \
			  bench_and_ops.c \
			  sort_stack.c \
			  libft_1.c \
			  libft_2.c \
			  libft_3.c \
			  libft_4.c \
			  print_bench.c \
			  free.c \
			  main.c

ALGORITHMS		= algorithm/simple.c \
			  algorithm/simple_greedy.c \
			  algorithm/simple_utils.c \
			  algorithm/medium.c \
			  algorithm/medium_utils.c \
			  algorithm/medium_pop.c \
			  algorithm/complex.c \
			  algorithm/complex_utils.c \
			  algorithm/complex_move.c \
			  algorithm/complex_sort_three.c \
			  algorithm/complex_small_sort.c

OPERATIONS		= operations/push.c \
			  operations/swap.c \
			  operations/rotate.c \
			  operations/reverse_rotate.c

CHECKER			= bonus/checker.c \
			  bonus/operations.c \
			  bonus/parse.c \
			  bonus/split.c \
			  bonus/utils.c \
			  bonus/list.c

SRCS			= $(MAIN_PROG) $(ALGORITHMS) $(OPERATIONS)
BONUS_SRCS		= $(OPERATIONS) $(CHECKER)

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

%.o	: %.c
	$(CC) $(CFLAGS) -I . -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

bonus	: .bonus_flag

.bonus_flag	: $(BONUS_OBJS)
	$(CC) $(BONUS_OBJS) -o $(BONUS_NAME)
	@touch .bonus_flag

clean	:
	$(RM) $(OBJS) $(BONUS_OBJS) .bonus_flag

fclean	: clean
	$(RM) $(NAME) $(BONUS_NAME)

re	: fclean all

.PHONY: all bonus clean fclean re
