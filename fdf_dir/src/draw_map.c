/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:21:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 06:42:13 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void		convert_map(t_map **map, double **mat)
static void		apply_point(t_map *point, double **mat);
static double	**map_easy_to_see(t_map **map);

int	draw_map(t_map **map, char *title)
{
	double mat[4][4];

	mat = {{0.707, 0.408, 0.0, 0.0},
	{0.0, 0.816, 0.0, 0.0},
	{-0.707, 0.408, 1.0, 0.0},
	{0.0, 0.0, 0.0, 1.0}};
	convert_map(map, &mat);
	mat = map_easy_to_see(map);
	convert_map(map, &mat);
	return (mlx_all_process(map, title));
}

static void	convert_map(t_map **map, double **mat)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col].end != 1)
		{
			apply_point(&map[row][col], mat);
			col++;
		}
		row++;
	}
}

static void	apply_point(t_map *point, double **mat)
{
	double	x;
	double	y;
	double	z;

	x = point->vx;
	y = point->vy;
	z = point->vz;
	point->vx = x * mat[0][0] + y * mat[1][0] + z * mat[2][0] + mat[3][0];
	point->vy = x * mat[0][1] + y * mat[1][1] + z * mat[2][1] + mat[3][1];
	point->vz = x * mat[0][2] + y * mat[1][2] + z * mat[2][2] + mat[3][2];
}
