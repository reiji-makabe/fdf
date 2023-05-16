/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 23:18:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/16 19:04:44 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	draw_rightward_on_screen(t_map *p_0, t_map *p_1, t_mlx *mlx);
static void	draw_leftward_on_screen(t_map *p_0, t_map *p_1, t_mlx *mlx);
static int	y_has_moved(int p_0_vy, int p_1_vy, int dx, int *d);

void	draw_line(t_map *p_0, t_map *p_1, t_data *img, t_mlx *mlx)
{
	if (p_0 == NULL || p_1 == NULL || p_1->end == 1)
		return ;
	img = img;
	if (p_0->vx < p_1->vx)
		draw_rightward_on_screen(p_0, p_1, mlx);
	else
		draw_leftward_on_screen(p_0, p_1, mlx);
}

static void	draw_rightward_on_screen(t_map *p_0, t_map *p_1, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = 2 * (p_1->vx - p_0->vx);
	dy = 2 * (p_1->vy - p_0->vy);
	x = p_0->vx;
	y = p_0->vy;
	d = -1 * (dx >> 1);
	while (x <= p_1->vx)
	{
		y += y_has_moved(p_0->vy, p_1->vy, dx, &d);
		d += dy;
		mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
		x++;
	}
}

static void	draw_leftward_on_screen(t_map *p_0, t_map *p_1, t_mlx *mlx)
{
	int	dx;
	int	dy;
	int	x;
	int	y;
	int	d;

	dx = 2 * (p_0->vx - p_1->vx);
	dy = 2 * (p_0->vy - p_1->vy);
	x = p_1->vx;
	y = p_1->vy;
	d = -1 * (dx >> 1);
	while (x <= p_0->vx)
	{
		y += y_has_moved(p_0->vy, p_1->vy, dx, &d);
		d += dy;
		mlx_pixel_put(mlx->mlx, mlx->window, x, y, p_0->color);
		x++;
	}
}

static int	y_has_moved(int p_0_vy, int p_1_vy, int dx, int *d)
{
	int	i;

	i = 0;
	if (p_0_vy < p_1_vy)
	{
		while (*d > 0)
		{
			*d -= dx;
			i++;
		}
	}
	else
	{
		if (*d < 0)
		{
			*d -= dx;
			i++;
		}
	}
	return (i);
}

//		my_mlx_pix_put_image(img, x, y, p_0->color);
