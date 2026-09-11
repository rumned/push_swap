NAME			= push_swap
BONUS_NAME		= checker

CC			= cc
CFLAGS			= -Wall -Wextra -Werror

AR			= ar rcs
RM			= rm -f

SRCS			= (file names to be added after finalised)
BONUS_SRCS		= "

OBJS			= $(SRCS:.c=.o)
BONUS_OBJS		= $(BONUS_SRCS:.c=.o)

%.o	: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

.PHONY: all bonus clean fclean re
