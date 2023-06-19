/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 16:59:00 by rmakabe           #+#    #+#             */
/*   Updated: 2023/06/15 20:12:43 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	put_value_t_color(t_draw *draw, t_color *color)
{
	color->start_c = draw->s->color;
	if (draw->s->color < draw->e->color)
	{
		color->diff_c = draw->e->color - draw->s->color;
		color->np = 1;
	}
	else if (draw->s->color > draw->e->color)
	{
		color->diff_c = draw->s->color - draw->e->color;
		color->np = -1;
	}
	else
	{
		color->np = 0;
		color->diff_c = 0;
	}
	if (color->np)
	color->length = sqrt(pow(draw->dx, 2) + pow(draw->dy, 2));
}

uint32_t	defined_pixel_color(t_draw *draw, int x, int y)
{
	double		ratio;
	t_color		*color;
	uint32_t	red;
	uint32_t	green;
	uint32_t	blue;

	color = draw->color;
	if (color->np == 0)
		return (color->start_c);
	ratio = sqrt(pow(x - draw->s->vx, 2) + pow(y - draw->s->vy, 2)) / color->length;
	red = (uint32_t)(((color->diff_c & 0xff0000) >> 16) * ratio) << 16;
	green = (uint32_t)(((color->diff_c & 0x00ff00) >> 8) * ratio) << 8;
	blue = ((color->diff_c & 0x0000ff)) * ratio;
	return (color->start_c + color->np * (red + green + blue));
}
