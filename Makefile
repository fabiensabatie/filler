# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2018/01/19 17:08:40 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Defining variables

NAME = libft.a
SRC_PATH = libft
OBJ_PATH = obj

PRINTF_SRC =

SRC_NAME =	ft_strjoin_char.c \
			ft_strjoinfree.c \
			ft_putendl_fd.c \
			spec_handlers.c \
			ft_putchar_fd.c \
			str_printers.c \
			ft_putnbr_fd.c \
			ft_putstr_fd.c \
			ft_lstdelone.c \
			ft_chartostr.c \
			ft_memalloc.c \
			ft_striteri.c \
			ft_strsplit.c \
			ft_putwchar.c \
			ft_wstrnsub.c \
			nb_printers.c \
			ft_wstrlen.c \
			ft_strnequ.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_isdigit.c \
			ft_isalpha.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_putchar.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_strncpy.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strrchr.c \
			ft_strnstr.c \
			ft_strncmp.c \
			ft_striter.c \
			ft_strmapi.c \
			ft_putendl.c \
			ft_lstiter.c \
			ft_strnsub.c \
			ft_strcsub.c \
			ft_putwstr.c \
			ft_chrcstr.c \
			ft_lstmap.c \
			ft_strsub.c \
			ft_lstnew.c \
			ft_strnew.c \
			ft_strequ.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_memdel.c \
			ft_strmap.c \
			ft_strdel.c \
			ft_strchr.c \
			ft_strclr.c \
			ft_memcmp.c \
			ft_memchr.c \
			ft_strstr.c \
			ft_strcmp.c \
			ft_putstr.c \
			ft_putnbr.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strstr.c \
			ft_strcat.c \
			ft_chrstr.c \
			ft_strlen.c \
			ft_memset.c \
			ft_memcpy.c \
			ft_strrev.c \
			ft_printf.c \
			handlers.c \
			ft_bzero.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_abs.c \
			buffer.c \

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
_SRC = $(addprefix ../,$(SRC))

CPPFLAGS = -Wall -Wextra -Werror
all: $(NAME)

$(NAME):
	@mkdir obj && cd obj && gcc $(CPPFLAGS) -c $(_SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

lik: re
	@gcc -Wall -Wextra -Werror ormain.c libftprintf.a -o printf
	@make fclean