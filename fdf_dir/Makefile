# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 19:53:21 by rmakabe           #+#    #+#              #
#    Updated: 2023/04/07 16:00:04 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ../fdf
CC := cc
SANITIZE :=-fsanitize=leak -fsanitize=address

ifdef WITH_DEBUG
	DEBUG :=-O0 -g3
endif

ifeq ($(shell uname), Linux)
	LINK_DIR := -L ../minilibx-linux -L /usr/lib
	LINK :=$(LINK_DIR) -lm -lz -lmlx -lXext -lX11
else
	LINK_DIR :=
	LINK :=$(LINK_DIR)
endif

# todo macOS


CFLAGS := -Wall -Wextra -Werror -lmlx $(DEBUG) $(SANITIZE) -I
RM := rm -rf
AR := ar -rcs

INCLUDE := include/
SRC_DIR := src/
OBJ_DIR := obj/
ARCHIVE_DIR := archive/
LIB_DIR := 42_library/

LIB := $(filter-out $(LIB_DIR)Makefile, $(wildcard $(LIB_DIR)*))
ARCHIVE := $(addsuffix .a, $(subst $(LIB_DIR), $(ARCHIVE_DIR), $(LIB)))

$(addpre)

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

re: fclean all

debug:
	make WITH_DEBUG=1

norm:
	@norminette $(SRC_DIR) $(INCLUDE) | grep Error || true

.PHONY: all clean fclean re debug norm
