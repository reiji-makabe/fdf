/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:18:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/14 04:53:46 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	draw_line(t_map *p_0, t_map *p_1, t_data *img, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	y;
	int	x;
	int	d;

	if (p_0 == NULL || p_1 == NULL || p_1->end == 1)
		return ;
	dx = 2 * (p_1->vx - p_0->vx);
	dy = 2 * (p_1->vy - p_0->vy);
	x = p_0->vx;
	y = p_0->vy;
	d = -dx >> 1;
	while (x <= p_1->vx)
}

x_kansuu syori
	{
		if (d > 0)
		{
			y = y + 1;
			d -= dx;
		}
		d += dy;
//		my_mlx_pix_put_image(img, x, y, p_0->color);
		img = img;
		mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
		x++;
	}
