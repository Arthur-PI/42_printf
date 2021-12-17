DEP_DIR	=	include/

SRC_DIR	=	src/

OBJ_DIR	=	bin/

CC		=	cc

AR		=	ar rc

RM		=	rm -rf

LIBFT_PATH	=	libft

CFLAGS	=	-Wall -Werror -Wextra -I$(DEP_DIR) -I$(LIBFT_PATH) -g3 #-fsanitize=address

NAME	=	libftprintf.a

SRCS	=	ft_printf.c \
			buffer_handler.c \
			option_pointer.c \
			option_number.c \
			option_string.c \
			option_char.c \
			option_hex.c \

OBJS	=	$(addprefix $(OBJ_DIR), $(SRCS:.c=.o))

all: 			$(NAME)

$(OBJ_DIR):
		mkdir -p $@

$(OBJ_DIR)%.o:	$(SRC_DIR)%.c
		$(CC) $(CFLAGS) -o $@ -c $<

libft.a:
		make bonus -C $(LIBFT_PATH)
		cp $(LIBFT_PATH)/libft.a ./$(NAME)

$(NAME):		libft.a $(OBJ_DIR) $(OBJS)
		$(AR) $(NAME) $(OBJS)

clean:
		$(RM) $(OBJ_DIR)

fclean:			clean
		$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re
