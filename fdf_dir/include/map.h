/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:52:48 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/16 17:38:42 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

typedef struct s_map
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	int			color;
}				t_map;

t_map	**create_map(int fd);
void	convert_isometric_map(t_map **map);
void	draw_map(t_map **map);

# endif
