/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 19:21:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/11 13:50:29 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

t_map	**init_map(int fd)
{
	double	mat[4][4] = {{0.707, -0.707, 0.0, 0.0},
	{0.408, 0.408, 0.816, 0.0},
	{-0.577, -0.577, 0.577, 0.0},
	{0.0, 0.0, 0.0, 1.0}};
	t_map	**map;
	double	**mat_p;

	map = create_map(fd);
	print_map(map);
	if (map == NULL)
		return (NULL);
	mat_p = make_matrix();
	if (mat_p == NULL)
	{
		clear_map(map);
		return (NULL);
	}
	mat_p = matrix_convert(mat, mat_p);
	mat_p = z_rotate_matrix(mat_p, 270);
	convert_map(map, mat_p);
	mat_p = matrix_unitize(mat_p);
	mat_p = map_easy_to_see(map, mat_p);
	convert_map(map, mat_p);
	clear_matrix(mat_p);
	return (map);
}

void	convert_map(t_map **map, double **mat)
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

void		apply_point(t_map *point, double **mat)
{
	double	x;
	double	y;
	double	z;

	x = point->vx;
	y = point->vy;
	z = point->vz;
	point->vx = x * mat[0][0] + y * mat[0][1] + z * mat[0][2] + mat[0][3];
	point->vy = x * mat[1][0] + y * mat[1][1] + -z * mat[1][2] + mat[1][3];
	point->vz = x * mat[2][0] + y * mat[2][1] + z * mat[2][2] + mat[2][3];
}
