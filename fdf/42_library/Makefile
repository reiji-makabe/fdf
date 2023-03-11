# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/11 21:23:55 by rmakabe           #+#    #+#              #
#    Updated: 2023/03/11 21:29:03 by rmakabe          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPRINTF := ft_printf/
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
	make WITH_DEBUG -C $(LIBFTPRINTF)
	make fclean -C $(GNL)

norm:
	make norm -C $(LIBFTPRINTF)
	make fclean -C $(GNL)

.PHONY: all clean fclean re debug norm
