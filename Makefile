LIBFT_DIR		=	./libft/
LIBFT 			= 	$(addprefix $(LIBFT_DIR), libft.a)

NAME 	= 	pipex
HEADER	=	pipex.h
CFLAGS	= 	-Wall -Werror -Wextra
CC 		= 	gcc
SRC		= 	pipex.c	\
			pipex_utils.c
OBJ		=	$(patsubst %.c, %.o, $(SRC))
RM		= 	rm -rf

HEADER_BONUS	= pipex_bonus.h
SRC_BONUS		= pipex_bonus.c \
					pipex_utils_bonus.c
OBJ_BONUS 		= $(patsubst %.c, %.o, $(SRC_BONUS))

all : 		$(NAME)

%.o :		%.c $(HEADER) $(HEADER_BONUS) Makefile
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME)	: 	$(OBJ) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ) -L libft/ -lft -o $(NAME)

$(LIBFT) :
			$(MAKE) -C $(LIBFT_DIR)

bonus:		$(OBJ_BONUS) $(LIBFT)
			$(CC) $(CFLAGS) $(OBJ_BONUS) -L libft/ -lft -o $(NAME)
clean :
			$(MAKE) clean -C $(LIBFT_DIR)
			$(RM) $(OBJ) $(OBJ_BONUS)

fclean : 	clean
			$(MAKE) fclean -C $(LIBFT_DIR)
			$(RM) $(NAME)

re :		fclean all

.PHONY: all clean fclean re
