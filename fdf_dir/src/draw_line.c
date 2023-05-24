/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:18:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/24 17:04:45 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	draw_loop_pos(t_map *p_0, t_mlx *mlx, t_draw *draw);
static void	draw_loop_neg(t_map *p_0, t_mlx *mlx, t_draw *draw);
static void	put_value_t_draw(t_map *p_0, t_map *p_1, t_draw *draw);
static int	num_is_moved(int p_0_v, int p_1_v, int dn, int *d);

void	draw_line(t_map *p_0, t_map *p_1, t_data *img, t_mlx *mlx)
{
	t_draw	draw;

	if (p_0 == NULL || p_1 == NULL || p_1->end == 1)
		return ;
	img = img;
	draw.dx = 2 * fabs((p_1->vx - p_0->vx));
	draw.dy = 2 * fabs((p_1->vy - p_0->vy));
	if (draw.dy <= draw.dx)
		draw.d = -1 * (draw.dx >> 1);
	else
		draw.d = -1 * (draw.dy >> 1);
	if (((p_0->vx <= p_1->vx) && (p_0->vy <= p_1->vy)) || ((p_1->vx <= p_0->vx) && (p_1->vy <= p_0->vy)))
		draw.x_and_y_is_pos = 1;
	else
		draw.x_and_y_is_pos = 0;
	put_value_t_draw(p_0, p_1, &draw);
	if (draw.x_and_y_is_pos)
		draw_loop_pos(p_0, mlx, &draw);
	else
		draw_loop_neg(p_0, mlx, &draw);
}

static void	put_value_t_draw(t_map *p_0, t_map *p_1, t_draw *draw)
{
	if (p_0->vx < p_1->vx)
		draw->s = p_0;
	else if (p_0->vx > p_1->vx)
		draw->s = p_1;
	else
	{
		if (p_0->vy < p_1->vy)
			draw->s = p_0;
		else
			draw->s = p_1;
	}
	if (!draw->x_and_y_is_pos)
	{
		if (draw->s == p_0)
			draw->s = p_1;
		else
			draw->s = p_0;
	}
	if (draw->s == p_0)
		draw->e = p_1;
	else
		draw->e = p_0;
}

static void	draw_loop_pos(t_map *p_0, t_mlx *mlx, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->s->vx;
	y = draw->s->vy;
	if (draw->dy < draw->dx)
	{
		while (x <= draw->e->vx)
		{
			y += num_is_moved(draw->s->vy, draw->e->vy, draw->dx, &(draw->d));
			draw->d += draw->dy;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
			x++;
		}
	}
	else
	{
		while (y <= draw->e->y)
		{
			x += num_is_moved(draw->s->vx, draw->e->vx, draw->dy, &(draw->d));
			draw->d += draw->dx;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
			y++;
		}
	}
}

static void	draw_loop_neg(t_map *p_0, t_mlx *mlx, t_draw *draw)
{
	int	x;
	int	y;

	x = draw->s->vx;
	y = draw->s->vy;
	if (draw->dy <= draw->dx)
	{
		while (x >= draw->e->vx)
		{
			y += num_is_moved(draw->s->vy, draw->e->vy, draw->dx, &(draw->d));
			draw->d += draw->dy;
			mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
			x--;
		}
	}
	else
	{
		while (y <= draw->e->y)
		{
			x -= num_is_moved(draw->e->vx, draw->s->vx, draw->dy, &(draw->d));
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
