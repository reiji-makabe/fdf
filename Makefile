# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 19:59:37 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/11 20:03:27 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILE := fdf/

ifdef WITH_DEBUG
	DEBUG :=-O0 -g3
endif

all:
	make -C $(FILE)

clean:
	make clean -C $(FILE)

fclean: clean
	make fclean -C $(FILE)

re: fclean all

debug:
	make WITH_DEBUG -C $(FILE)

norm:
	make norm -C $(FILE)

.PHONY: all clean fclean re debug norm
