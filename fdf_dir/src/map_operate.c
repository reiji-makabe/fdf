/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_operate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 18:05:09 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/22 22:46:59 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static uint32_t	char_a_hex_to_uint32t(char *hex);
static uint32_t	if_color_exist_fill_it(char *z);

void	fill_map_point(int x, int y, char *z, t_map *point)
{
	int			z_num;
	uint32_t	color;

	z_num = ft_atoi(z);
	color = if_color_exist_fill_it(z);
	point->x = x;
	point->y = y;
	point->z = z_num;
	point->vx = x;
	point->vy = y;
	point->vz = z_num;
	point->color = color;
	point->end = 0;
}

static uint32_t	if_color_exist_fill_it(char *z)
{
	int			i;
	char		**str;
	uint32_t	color;

	i = 0;
	str = NULL;
	color = 0x00;
	while (z[i] != 0)
	{
		if (z[i] == ',')
		{
			str = ft_split(z, ',');
			color = char_a_hex_to_uint32t(str[1]);
			i++;
		}
	}
	free(str);
	return (color);
}

static uint32_t	char_a_hex_to_uint32t(char *hex)
{
	char		*num_u;
	uint32_t	re;
	int			i;

	re = 0;
	num_u = "0123456789abcdef";
	hex += 2;
	while (*hex != 0)
	{
		i = 0;
		while (num_u[i] != *hex || num_u[i] == 0)
			i++;
		re = re * 16 + i;
		hex++;
	}
	return (re);
}

void	clear_map(t_map **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		free(map[i++]);
	free(map);
}
