/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:21:40 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/13 17:33:17 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_map	**create_map(int fd)
{
	t_map	**map;
	char	*row;

	row = get_next_line(fd);
	while (row != NULL)
	{
	}
}