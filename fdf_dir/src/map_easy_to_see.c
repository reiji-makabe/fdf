/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_easy_to_see.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 03:01:31 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 05:01:04 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int		return_coordinate_max_and_min(t_map **map, int &max_x, int &max_y, int &min_y);
static double	**zoom_matrix(double **mat, int x, int y);

double	**map_easy_to_see(t_map **map)
{
	int		max_x;
	int		max_y;
	int		min_x;
	int		min_y;
	double	**re;

	max_x = INT_MIN;
	max_y = INT_MIN;
	min_x = INT_MAX;
	min_y = return_coordinate_max_and_min(map, max_x, max_y, min_x);
	re = {{1, 0, 0, SIZE_X / 2 - (max_x + min_x) / 2},
	{0, 1, 0, SIZE_Y / 2 - (max_y + min_y) / 2},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	return (zoom_matrix(re, max_x - min_x, max_y - min_y));
}

static void	return_coordinate_max_and_min(t_map **map, int &max_x, int &max_y, int &min_y)
{
	int	row;
	int	col;
	int	min_y;

	min_y = INT_MAX;
	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col]->end != 1)
		{
			if (map[row][col]->x > max_x)
				max_x = map[row][col]->x;
			else if (map[row][col]->y > max_y)
				max_y = map[row][col]->y;
			else if (map[row][col]->x < min_x)
				min_x = map[row][col]->x;
			else if (map[row][col]->y < min_y)
				min_y = map[row][col]->y;
			col++;
		}
		row++;
	}
	return (min_y);
}

static double	**zoom_matrix(double **mat, int x, int y)
{
	int		mag_x;
	int		mag_y;
	double	re;

	mag_x = SIZE_X / x;
	mag_y = SIZE_Y / y;
	if (mag_x > mag_y)
		mag_x = mag_y;
	re = {{mag_x, 0, 0, re[0][3] * mag_x},
	{0, mag_x, 0, re[1][3] * mag_x},
	{0, 0, 1, 0},
	{0, 0, 0, 1}};
	return (re);
}
