/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_all_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:49:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/31 06:38:00 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	my_mlx_init(t_mlx *mlx, t_data *img, char *title);
static void	mlx_draw_map(t_map **map, t_data *img, t_mlx *mlx);

int	mlx_all_process(t_map **map, char *title)
{
	t_mlx	mlx;
	t_data	img;

	if (my_mlx_init(&mlx, &img, title))
		return (1);
//	mlx_hook(mlx.window, 2, 1L<<0, close_mlx, &mlx);
	mlx_draw_map(map, &img, &mlx);
	mlx_put_image_to_window(mlx.mlx, mlx.window, img.img, SIZE_X, SIZE_Y);
	mlx_destroy_image(mlx.mlx, img.img);
	clear_map(map);
	return (mlx_loop(mlx.mlx));
}

static int	my_mlx_init(t_mlx *mlx, t_data *img, char *title)
{
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		return (1);
	mlx->window = mlx_new_window(mlx->mlx, SIZE_X, SIZE_Y, title);
	if (mlx->window == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		return (1);
	}
	img->img = mlx_new_image(mlx->mlx, SIZE_X, SIZE_Y);
	if (img->img == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		return (1);
	}
	img->addr = mlx_get_data_addr(img->img, &(img->bpp)
		, &(img->size_l), &(img->endian));
	return (0);
}

void	my_mlx_pix_put_image(t_data *data, int x, int y, uint32_t color)
{
	char	*dst;

	dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	mlx_draw_map(t_map **map, t_data *img, t_mlx *mlx)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col].end != 1)
		{
			draw_line(&map[row][col], &map[row][col + 1], img, mlx);
			if (map[row + 1] != NULL)
				draw_line(&map[row][col], &map[row + 1][col], img, mlx);
			col++;
		}
		row++;
	}
}
