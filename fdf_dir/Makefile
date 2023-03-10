# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 19:53:21 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/12 02:39:06 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../fdf
CC := cc
SANITIZE :=-fsanitize=leak -fsanitize=address

ifdef WITH_DEBUG
	DEBUG :=-O0 -g3
endif

CFLAGS := -Wall -Wextra -Werror $(DEBUG) $(SANITIZE) -I
RM := rm -rf
AR := ar -rcs
LINK_DIR := -L ../minilibx-linux/
LINK :=-lm -lmlx -lXext -lX11 $(LINK_DIR)

INCLUDE := include/
SRC_DIR := src/
OBJ_DIR := obj/
ARCHIVE_DIR := archive/
LIB_DIR := 42_library/

LIB := $(filter-out $(LIB_DIR)Makefile, $(wildcard $(LIB_DIR)*))
ARCHIVE := $(addsuffix .a, $(subst $(LIB_DIR), $(ARCHIVE_DIR), $(LIB)))

SRC := $(wildcard $(SRC_DIR)*.c)
OBJ := $(addprefix $(OBJ_DIR), $(notdir $(SRC:.c=.o)))

#command
all: $(NAME)

$(NAME):$(OBJ)
	mkdir -p $(OBJ_DIR)
	make $(ARCHIVE)
	$(CC) $(CFLAGS) $(INCLUDE) $^ -o $(NAME) $(ARCHIVE) $(LINK)


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
	$(RM) $(NAME) $(ARCHIVE)

norm:
	@norminette $(SRC_DIR) $(INCLUDE) | grep Error || true

.PHONY: all clean fclean re debug norm
