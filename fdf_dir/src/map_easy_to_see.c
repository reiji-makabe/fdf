/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_easy_to_see.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:01:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/15 20:38:27 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	derive_number(t_map **map, double *move_x, double *move_y, double *zoom_num);
static double	return_coordinate_max_and_min(t_map **map, double *max_x,
					double *max_y, double *min_x);

double	**map_easy_to_see(t_map **map, double **mat)
{
	double	move_x;
	double	move_y;
	double	zoom_num;

	derive_number(map, &move_x, &move_y, &zoom_num);
	mat = zoom_matrix(mat, zoom_num, zoom_num);
	convert_map(map, mat);
	mat = matrix_unitize(mat);
	derive_number(map, &move_x, &move_y, &zoom_num);
	mat = move_matrix(mat, move_x, move_y);
	convert_map(map, mat);
	return (mat);
}

static void	derive_number(t_map **map, double *move_x, double *move_y, double *zoom_num)
{
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;

	max_x = INT_MIN;
	max_y = INT_MIN;
	min_x = INT_MAX;
	min_y = return_coordinate_max_and_min(map, &max_x, &max_y, &min_x);
	*zoom_num = SIZE_X / (max_x - min_x) / 2;
	if (*zoom_num > (SIZE_Y / (max_y - min_y) / 2))
		*zoom_num = SIZE_Y / (max_y - min_y) / 2;
	*move_x = (SIZE_X - (max_x + min_x)) / 2;
	*move_y = (SIZE_Y - (max_y + min_y)) / 2;
}


static double	return_coordinate_max_and_min(t_map **map, double *max_x,
					double *max_y, double *min_x)
{
	int		row;
	int		col;
	double	min_y;

	min_y = INT_MAX;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col].end != 1)
		{
			if (map[row][col].vx > *max_x)
				*max_x = map[row][col].vx;
			else if (map[row][col].vy > *max_y)
				*max_y = map[row][col].vy;
			else if (map[row][col].vx < *min_x)
				*min_x = map[row][col].vx;
			else if (map[row][col].vy < min_y)
				min_y = map[row][col].vy;
			col++;
		}
		row++;
	}
	return (min_y);
}
