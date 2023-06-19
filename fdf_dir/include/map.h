/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 02:52:48 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/15 20:24:01 by rmakabe          ###   ########.fr       */
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

typedef struct s_color
{
	uint32_t	start_c;
	uint32_t	diff_c;
	double		length;
	int			np;
}				t_color;

typedef struct s_draw
{
	t_map	*s;
	t_map	*e;
	t_color	*color;
	int		dx;
	int		dy;
	int		d;
	int		x_and_y_is_pos;
}				t_draw;

t_map	**create_map(int fd);
t_map	**init_map(int fd);
void	convert_map(t_map **map, double **mat);
void	apply_point(t_map *point, double **mat);
void	clear_map(t_map **map);

double	**make_matrix(void);
double	**matrix_convert(double mat_li[4][4], double **mat);
double	**matrix_unitize(double **mat);
void	matrix_copy(double mat_li[4][4], double **mat);
void	clear_matrix(double **mat);


void	fill_map_point(int x, int y, char *z, t_map *point);
double	**map_easy_to_see(t_map **map, double **mat);
double	**zoom_matrix(double **mat, double magnifi_x, double magnifi_y);
double	**move_matrix(double **mat, double x, double y);
double	**z_rotate_matrix(double **mat, int degree);

int		mlx_all_process(t_map **map, char *title);
void	my_mlx_pix_put_image(t_data *data, int x, int y, t_draw *draw);
void	draw_line(t_map *p_0, t_map *p_1, t_data *img);
int		close_mlx(t_mlx *mlx);
void	put_value_t_color(t_draw *draw, t_color *color);
uint32_t	defined_pixel_color(t_draw *draw, int x, int y);

void	print_map(t_map **map);
#endif
