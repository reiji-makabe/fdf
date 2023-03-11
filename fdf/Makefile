# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 19:53:21 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/11 22:08:19 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf
CC := cc
SANITIZE :=-fsanitize=leak -fsanitize=address

ifdef WITH_DEBUG
	DEBUG :=-O0 -g3
endif

CFLAGS := -Wall -Wextra -Werror $(DEBUG) $(SANITIZE) -I
RM := rm -rf
AR := ar -rcs


INCLUDE := include/
SRC_DIR := src/
OBJ_DIR := obj/
ARCHIVE_DIR := archive/
LIB_DIR := 42_library/
LINK :=-lm -mlx -lXext -lX11

SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))
ARCHIVE := $(wildcard $(ARCHIVE_DIR)*.a)

all: $(NAME)

$(NAME):$(OBJ)
	mkdir -p $(OBJ_DIR)
	make $(ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME) $(ARCHIVE)


$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(ARCHIVE):
ifdef WITH_DEBUG
	make debug -C $(LIB_DIR)
else
	make -C $(LIB_DIR)
endif

clean:
	$(RM) $(OBJ)

fclean: clean
	make fclean -C $(LIB_DIR)
	$(RM) $(NAME) $(ARCHIVE_DIR)

norm:
	@norminette $(SRC_DIR) $(INCLUDE) | grep Error || true

.PHONY: all clean fclean re debug norm
