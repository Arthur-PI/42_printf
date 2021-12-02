DEP_DIR	=	include/

SRC_DIR	=	src/

OBJ_DIR	=	bin/

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -I$(DEP_DIR) -g3 -fsanitize=address

NAME	=	libftprintf.a

LIBFT_PATH	=	libft

SRCS	=	ft_printf.c \

OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: 			$(NAME)

$(OBJ_DIR):
		mkdir -p $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		$(CC) $(CFLAGS) -I$(LIBFT_PATH) -o $@ -c $<

libft.a:
		make bonus -C $(LIBFT_PATH)
		cp $(LIBFT_PATH)/libft.a ./

$(NAME):		libft.a $(OBJ_DIR) $(OBJS)
		ar rc $(NAME) $(OBJS) libft.a

clean:
		rm -rf $(OBJ_DIR)
		rm -rf libft.a

fclean:			clean
		rm -rf $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
