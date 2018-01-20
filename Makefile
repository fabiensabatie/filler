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

NAME = fsabatie.filler
LIB_NAME = libft.a
SRC_PATH = libft
FILL_PATH = srcs
OBJ_PATH = obj

FILL_SRC =	filler.c \
			play.c

SRC_NAME =	ft_strjoin_char.c \
			ft_strjoinfree.c \
			get_next_line.c \
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
			ft_retsplit.c \
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

FILL_OBJ_NAME = $(FILL_SRC:.c=.o)
FILL_OBJ = $(addprefix $(OBJ_PATH)/,$(FILL_OBJ_NAME))
FILLER_SRC = $(addprefix $(FILL_PATH)/,$(FILL_SRC))
_FILL_SRC = $(addprefix ../,$(FILLER_SRC))


CPPFLAGS = -Wall -Wextra -Werror -g
all: $(NAME)

$(NAME):
	@mkdir obj && cd obj && gcc $(CPPFLAGS) -c $(_SRC)
	@ar rc $(LIB_NAME) $(OBJ)
	@ranlib $(LIB_NAME)
	@cd obj && gcc $(CPPFLAGS) -c $(_FILL_SRC)
	@gcc $(CPPFLAGS) -o $(NAME) $(FILL_OBJ) $(LIB_NAME)
	@mv $(NAME) players/
	@rm -rf $(LIB_NAME)

clean:
	@rm -rf $(OBJ_PATH)

fclean: clean
	@rm -rf players/$(NAME)

re: fclean all