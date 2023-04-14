/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_all_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 20:49:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 06:10:29 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	mlx_draw(t_data **img, void *mlx, void *window, t_data *img);
static void	my_mlx_pix_put_image(t_data **data, int x, int y, int color);
static void	draw_line(t_map *point_0, t_map *point_1);

int	mlx_all_process(t_map **map, char *title)
{
	void	*mlx;
	void	*window;
	t_data	img;


	mlx = mlx_init();
	if (mlx == NULL)
		return (1);
	window = mlx_new_window(mlx, SIZE_X, SIZE_Y, );
	if (window == NULL)
	{
		mlx_destroy_display(mlx);
		return (1);
	}
	img.img = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	if (img.img == NULL)
	{
		mlx_destroy_window(mlx, window);
		mlx_destroy_display(mlx);
		return (1);
	}
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.size_l, &img.endian);
	return (mlx_draw(mlx, window, &img));
}

static void	my_mlx_pix_put_image(t_data **data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->size_l + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

static int	mlx_draw(t_data **img, void *mlx, void *window, t_data *img)
{
	int	row;
	int	col;

	row = 0;
	while (map[row])
	{
		col = 0;
		while (map[row][col].end != 1)
		{
			draw_line(&map[row][col], &map[row][col + 1]);
			draw_line(&map[row][col], &map[row + 1][col]);
			col++;
		}
		row++;
	}
}

static void	draw_line(t_map *point_0, t_map *point_1)
{
	if (point_0 == NULL || point_1 == NULL || point_1->end == 1)
		return ;

}
