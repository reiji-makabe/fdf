# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 21:23:55 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/16 19:10:14 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPRINTF := libftprintf/
GNL := get_next_line/

ifdef WITH_DEBUG
	DEBUG :=-O0 -g3
endif

all:
	make -C $(LIBFTPRINTF)
	make -C $(GNL)

clean:
	make clean -C $(LIBFTPRINTF)
	make clean -C $(GNL)

fclean: clean
	make fclean -C $(LIBFTPRINTF)
	make fclean -C $(GNL)

re: fclean all

debug:
	make WITH_DEBUG=1 -C $(LIBFTPRINTF)
	make WITH_DEBUG=1 -C $(GNL)

norm:
	make norm -C $(LIBFTPRINTF)
	make norm -C $(GNL)

.PHONY: all clean fclean re debug norm
