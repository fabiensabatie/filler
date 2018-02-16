# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 17:18:12 by fsabatie          #+#    #+#              #
#    Updated: 2018/02/16 11:25:45 by fsabatie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY : all clean fclean re

# Defining variables

NAME = fsabatie.filler
LIB_NAME = libft.a
LIB_PATH = ./libft
FILL_SRCS = ../srcs
BUILD_PATH = build

FILL_SRC_F =	filler.c play.c map.c piece.c

OBJ_NAME = $(FILL_SRC_F:.c=.o)
OBJS = $(addprefix $(BUILD_PATH)/,$(OBJ_NAME))
SRCS = $(addprefix $(FILL_SRCS)/,$(FILL_SRC_F))
LIB = $(addprefix $(LIB_PATH)/,$(LIB_NAME))

# Compilation flags

CC = gcc
CPPFLAGS = -Wall -Wextra -Werror -g

# Defining rules

all: $(NAME)

$(NAME):
	@make -C $(LIB_PATH)
	@mkdir $(BUILD_PATH) && cd $(BUILD_PATH) && $(CC) $(CPPFLAGS) -c $(SRCS)
	@$(CC) $(CPPFLAGS) -o $(NAME) $(OBJS) $(LIB)
	@mv $(NAME) players/

clean:
	@make clean -C $(LIB_PATH)
	@rm -rf $(BUILD_PATH)

fclean: clean
	@make fclean -C $(LIB_PATH)
	@rm -rf players/$(NAME)

re: fclean all
