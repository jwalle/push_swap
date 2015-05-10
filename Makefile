NAME = push_swap

SRC = 	main.c \
		stock.c \
		sort.c \
		swap_one.c \
		swap_two.c \
		ft_chaos.c \
		ft_algo.c \

OBJ			=	$(SRC:.c=.o)

INC			=	-I./ -I./libft/include
LINK		=	-L./libft -lft

CFLAGS		=	-Wall -Wextra -Werror
CC			=	/usr/bin/gcc
RM			=	/bin/rm -v

all			:	$(NAME)

$(NAME)		:
	#make -C ./libft
	$(CC) $(CFLAGS) $(SRC) $(LINK) $(INC) -o $(NAME)
	#make -C ./libft clean
	rm -rf $(OBJ)


fclean		:	clean
	#make -C ./libft fclean
	rm -rf $(NAME)

re			:	fclean all

extra       :   FLAGS += $(EXTRAFLAGS)
extra       :   re

.PHONY: re fclean clean extra
