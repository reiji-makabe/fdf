/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:21:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/18 19:06:13 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	convert_isometric_map(t_map **map);
static void	apprly_point_isometric(t_map *point);

void	draw_map(t_map **map)
{
	convert_isometric_map(map);
}

static void	convert_isometric_map(t_map **map)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		apprly_point_isometric(&map[row][col]);
		col++;
		while (!(map[row][col].x == 0 && map[row][col].y == 0
				&& map[row][col].z == 0))
			apprly_point_isometric(map[row][col]);
		row++;
	}
}


static void	apprly_point_isometric(t_map *point)
{
	double	mat[4][4];
	double	x;
	double	y;
	double	z;

	mat = {{0.707, 0.408, 0.0, 0.0},
		{0.0, 0.816, 0.0, 0,0},
		{-0.707, 0.408, 1.0, 0.0},
		{0.0, 0.0, 0.0, 1.0},}
	x = point->x;
	y = point->y;
	z = point->z;
	point->vx = x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + mat[3][0];
	point->vy = x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + mat[3][1];
	point->vz = x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + mat[3][2];
}








