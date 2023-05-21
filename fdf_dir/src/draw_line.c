/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:18:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/21 12:04:52 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	draw_loop(t_map *p_0, t_map *p_1, t_mlx *mlx, t_draw *draw);
static void	put_value_t_draw(t_map *p_0, t_map *p_1, t_draw *draw);
static int	num_is_moved(int p_0_v, int p_1_v, int dn, int *d);

void	draw_line(t_map *p_0, t_map *p_1, t_data *img, t_mlx *mlx)
{
	t_draw	draw;

	if (p_0 == NULL || p_1 == NULL || p_1->end == 1)
		return ;
	img = img;
	put_value_t_draw(p_0, p_1, &draw);
	if (draw.dy < draw.dx)
		draw.d = -1 * (draw.dx >> 1);
	else
		draw.d = -1 * (draw.dy >> 1);
	draw_loop(p_0, p_1, mlx, &draw);
}

static void	put_value_t_draw(t_map *p_0, t_map *p_1, t_draw *draw)
{
	if (p_0->vx <= p_1->vx)
	{
		draw->dx = 2 * (p_1->vx - p_0->vx);
		draw->start_x = p_0->vx;
		draw->end_x = p_1->vx;
	}
	else
	{
		draw->dx = 2 * (p_0->vx - p_1->vx);
		draw->start_x = p_1->vx;
		draw->end_x = p_0->vx;
	}
	if (p_0->vy < p_1->vy)
	{
		draw->dy = 2 * (p_1->vy - p_0->vy);
		draw->start_y = p_0->vy;
		draw->end_y = p_1->vy;
	}
	else
	{
		draw->dy = 2 * (p_0->vy - p_1->vy);
		draw->start_y = p_1->vy;
		draw->end_y = p_0->vy;
	}
}

static void	draw_loop(t_map *p_0, t_map *p_1, t_mlx *mlx, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->start_x;
	y = draw->start_y;
	if (draw->dy < draw->dx)
	{
		while (x <= draw->end_x)
		{
			y += num_is_moved(draw->start_y, draw->end_y, draw->dx, &(draw->d));
			draw->d += draw->dy;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
			x++;
		}
	}
	else
	{
		while (y <= draw->end_y)
		{
			x += num_is_moved(draw->start_x, draw->end_x, draw->dy, &(draw->d));
			draw->d += draw->dx;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
			y++;
		}
	}
}

static int	num_is_moved(int p_0_v, int p_1_v, int dn, int *d)
{
	int	i;

	i = 0;
	if (p_0_v <= p_1_v)
	{
		while (*d > 0)
		{
			*d -= dn;
			i++;
		}
	}
	else
	{
		while (*d < 0)
		{
			*d -= dn;
			i++;
		}
	}
	return (i);
}

//		my_mlx_pix_put_image(img, x, y, p_0->color);
