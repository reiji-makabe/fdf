/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:05:09 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 02:12:46 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	fill_map_point(int x, int y, int z, t_map *point)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->vx = 0;
	point->vy = 0;
	point->vz = 0;
	point->end = 0;
	point->end = 0;
}
