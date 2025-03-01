CC = cc
CFLAGS = -Wall -Wextra -Werror 
NAME = push_swap
BONUS = checker
RM = rm -f

SRCS = Algo/main_sorting.c Algo/small_stacks.c Algo/some_utils.c Algo/bubble_sort.c \
	error.c Libft/ft_split.c Libft/others.c Moves/push.c Moves/rev_rotate.c \
	Moves/rotate.c Moves/swap.c push_swap.c stack_builder_utils.c stack_builder.c

BONUS_SRCS = Libft/others.c Libft/ft_split.c stack_builder.c stack_builder_utils.c error.c \
			Bonus_utils/errror.c Bonus_utils/check_push.c Bonus_utils/check_rev_rotate.c \
			Bonus_utils/check_rotate.c Bonus_utils/check_swap.c my_checker.c Bonus_utils/get_next_line.c \
			Bonus_utils/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS)

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean 
	$(RM) $(NAME) $(BONUS)
	
re: fclean all

both: all bonus

.PHONY: clean fclean re all bonus both 
