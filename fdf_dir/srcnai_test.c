/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   srcnai_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:47:08 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 01:32:13 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "get_next_line.h"
#include "ft_printf.h"
#include "map.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	void	*mlx;
	void	*window;
	void	*image;

	mlx = mlx_init();
	if (window == NULL)
		return (1);
	window = mlx_new_window(mlx, SIZE_X, SIZE_Y, "title");
	if (window == NULL)
	{
		mlx_destroy_display(mlx);
		return (1);
	}
	image = mlx_new_image(mlx, SIZE_X, SIZE_Y);
	if (image == NULL)
	{
		mlx_destroy_window(mlx, window);
		mlx_destroy_display(mlx);
	}
	// nanka iroiro imageni kaku
	mlx_put_image_to_window (mlx, window, image, SIZE_X, SIZE_Y);
	int num = 0;
	while (num < 1000)
	{
		mlx_pixel_put(mlx, window, num, num, 0x00ff0000);
		num++;
	}
	return (mlx_loop(mlx));
}
int	if_little_endian(void)
{
	int	x;
	x = 0x00000001;

	if (*(char *)&x)
		return (1);
	else
		return (0);
}


//int	main()
//{
//	t_map **map = (t_map **)malloc(sizeof(t_map *) * 3);
//	map[0] = (t_map *)malloc(sizeof(t_map) * 5);
//	map[0][0].x = 1;
//	printf("%f", map[0][0].x);
//}
//
//
//void	draw_map(t_map **map)
//{
//	int		row;
//	int		col;
//	t_map	now;
//
//	row = 0;
//	while (map[row])
//	{
//		col = 0;
//		now = map[row][col];
//		printf("%d ", (int)now.y);
//		col++;
//		now = map[row][col];
//		while (!(now.x == 0 && now.y == 0 && now.z == 0))
//		{
//			printf("%d ", (int)now.y);
//			col++;
//			now = map[row][col];
//		}
//		printf("\n", row);
//		row++;
//	}
//}
