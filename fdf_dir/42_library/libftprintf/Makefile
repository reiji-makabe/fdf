# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/17 17:01:33 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/12 02:16:02 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ARCHIVE := ../../archive/
NAME := $(ARCHIVE)libftprintf.a
CC := cc

ifdef WITH_DEBUG
	DEBUG := -O0 -g3
endif

CFLAGS := -Wall -Wextra -Werror $(DEBUG) -I
LIBFT_DIR := ./libft/
LIBFT := $(ARCHIVE)libft.a
RM := rm -rf
AR := ar -rcs


INCLUDE := include
SRC_DIR := src
OBJ_DIR := obj

SRC := $(wildcard $(SRC_DIR)/*.c)
OBJ := $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all: $(NAME)

$(NAME):$(OBJ)
	make -C $(LIBFT_DIR)
	mv $(ARCHIVE)libft.a $(NAME)
	$(AR) $(NAME) $(OBJ)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@


clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

debug:
	make WITH_DEBUG=1

norm:
	norminette src/* include/* libft/*.c libft/*.h | grep Error || true

.PHONY: all clean fclean re debug norm
