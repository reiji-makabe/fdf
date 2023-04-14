/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:52:48 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 05:08:56 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>

# define SIZE_X 900
# define SIZE_Y 900

typedef struct s_map
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	int			color;
	int			end;
}				t_map;

//image
//bits_per_pixel
//size_line
typedef struct s_data
{
	void	*img;
	int		bpp;
	int		size_l;
	int		endian;
	char	*addr;
}				t_data;

t_map	**create_map(int fd);
int		draw_map(t_map **map, char *title);

void	fill_map_point(int x, int y, int z, t_map *point);
double	**map_easy_to_see(t_map **map);

int		mlx_all_process(t_map **map, char *title);

#endif
