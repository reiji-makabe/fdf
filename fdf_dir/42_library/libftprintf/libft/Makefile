# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/01 17:35:19 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/14 00:20:18 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
CC := cc

ifdef WITH_DEBUG
	DEBUG := -O0 -g3
endif

CFLAGS := -Wall -Wextra -Werror $(DEBUG) -I
RM := rm -rf
AR := ar -rcs

INCLUDE := ../../../include/
SRC_DIR := src/
OBJ_DIR := obj/

SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))


# command
all: $(NAME)

$(NAME):$(OBJ)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug:
	make WITH_DEBUG=1

norm:
	norminette $(SRC_DIR) $(INCLUDE) | grep Error || true

.PHONY: all clean fclean re norm debug
