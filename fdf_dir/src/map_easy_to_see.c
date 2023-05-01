/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_easy_to_see.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:01:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/22 22:31:10 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static double	return_coordinate_max_and_min(t_map **map, double *max_x,
					double *max_y, double *min_x);
static double	**zoom_matrix(double **mat, double x, double y);
static double	**move_matrix(double **mat, double max_x_plus_min_x,
					double max_y_plus_min_y);

double	**map_easy_to_see(t_map **map, double **mat)
{
	double	max_x;
	double	max_y;
	double	min_x;
	double	min_y;

	max_x = INT_MIN;
	max_y = INT_MIN;
	min_x = INT_MAX;
	min_y = return_coordinate_max_and_min(map, &max_x, &max_y, &min_x);
	mat = move_matrix(mat, max_x + min_x, max_y + min_y);
	return (zoom_matrix(mat, max_x - min_x, max_y - min_y));
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
			if (map[row][col].x > *max_x)
				*max_x = map[row][col].x;
			else if (map[row][col].y > *max_y)
				*max_y = map[row][col].y;
			else if (map[row][col].x < *min_x)
				*min_x = map[row][col].x;
			else if (map[row][col].y < min_y)
				min_y = map[row][col].y;
			col++;
		}
		row++;
	}
	return (min_y);
}

//	re = {{1, 0, 0, SIZE_X / 2 - (max_x + min_x) / 2},
//	{0, 1, 0, SIZE_Y / 2 - (max_y + min_y) / 2},
//	{0, 0, 1, 0},
//	{0, 0, 0, 1}};
static double	**move_matrix(double **mat, double max_x_plus_min_x,
					double max_y_plus_min_y)
{
	mat[0][0] = 1;
	mat[0][1] = 0;
	mat[0][2] = 0;
	mat[0][3] = SIZE_X / 2 - (max_x_plus_min_x) / 2;
	mat[1][0] = 0;
	mat[1][1] = 1;
	mat[1][2] = 0;
	mat[1][3] = SIZE_Y / 2 - (max_y_plus_min_y) / 2;
	mat[2][0] = 0;
	mat[2][1] = 0;
	mat[2][2] = 1;
	mat[2][3] = 0;
	mat[3][0] = 0;
	mat[3][1] = 0;
	mat[3][2] = 0;
	mat[3][3] = 1;
	return (mat);
}

//	re = {{mag_x, 0, 0, mat[0][3] * mag_x},
//	{0, mag_x, 0, mat[1][3] * mag_x},
//	{0, 0, 1, 0},
//	{0, 0, 0, 1}};
static double	**zoom_matrix(double **mat, double x, double y)
{
	int		mag_x;
	int		mag_y;

	mag_x = SIZE_X / x;
	mag_y = SIZE_Y / y;
	if (mag_x > mag_y)
		mag_x = mag_y;
	mat[0][0] *= mag_x;
	mat[0][3] *= mag_x;
	mat[1][1] *= mag_x;
	mat[1][3] *= mag_x;
	return (mat);
}
