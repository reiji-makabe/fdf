/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:52:48 by rmakabe           #+#    #+#             */
/*   Updated: 2023/05/24 03:18:10 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "get_next_line.h"
# include <limits.h>
# include <math.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdint.h>

# define SIZE_X 1200
# define SIZE_Y 800

# define WHITE 0xffffffff

typedef struct s_map
{
	double		x;
	double		y;
	double		z;
	double		vx;
	double		vy;
	double		vz;
	uint32_t	color;
	int			end;
}				t_map;

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}			t_mlx;

//image
//bits_per_pixel
//size_line
typedef struct s_data
{
	void	*img;
	int		bpp;
	int		size_l;
	int		endian;
	char	*addr;
}				t_data;

typedef struct s_draw
{
	t_map	*s;
	t_map	*e;
	int	dx;
	int	dy;
	int	d;
	int	x_and_y_is_pos;
}				t_draw;

t_map	**create_map(int fd);
t_map	**init_map(int fd);
void	convert_map(t_map **map, double **mat);
void	apply_point(t_map *point, double **mat);
void	clear_map(t_map **map);

double	**make_matrix(void);
double	**matrix_convert(double mat_li[4][4], double **mat);
void	matrix_copy(double mat_li[4][4], double **mat);
void	clear_matrix(double **mat);

void	fill_map_point(int x, int y, char *z, t_map *point);
double	**map_easy_to_see(t_map **map, double **mat);
double	**zoom_matrix(double **mat, double magnifi);
double	**move_matrix(double **mat, double x, double y);
double	**anticlock_rotate_matrix(double **mat, int degree);

int		mlx_all_process(t_map **map, char *title);
void	my_mlx_pix_put_image(t_data *data, int x, int y, uint32_t color);
void	draw_line(t_map *p_0, t_map *p_1, t_data *img, t_mlx *mlx);
int		close_mlx(t_mlx *mlx);

void	print_map(t_map **map);
#endif
