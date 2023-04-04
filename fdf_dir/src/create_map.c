/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:21:40 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/14 17:50:58 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static t_map	**read_map(int fd, int row);
static t_map	*fill_map_row(char *txt, int index);
static void		fill_map_point(int x, int y, int z, t_map *point);

t_map	**create_map(int fd)
{
	t_map	**map;

	errno = 0;
	map = read_map(fd, 0);
	if (map == NULL)
	{
		perror("Error");
		exit(errno);
	}
	return (map);
}

static t_map	**read_map(int fd, int row)
{
	char	*txt;
	t_map	**re;

	txt = get_next_line(fd);
	if (txt != NULL)
		re = read_map(fd, row + 1);
	else
	{
		re = (t_map **)ft_calloc(sizeof(t_map *), (row + 1));
		if (re == NULL)
		{
			free(txt);
			return (re);
		}
		re[row] = NULL;
		return (re);
	}
	if (re == NULL)
	{
		free(txt);
		return (re);
	}
	re[row] = fill_map_row(txt, row);
	free(txt);
	if (re[row] == NULL)
		return (NULL);
	return (re);
}
//		re[now] nanka_syori_hituyou_free;


static t_map	*fill_map_row(char *txt, int index)
{
	int		*val;
	size_t	i;
	size_t	j;
	t_map	*map;

	val = char_a_to_int_a(txt, &i);
	map = (t_map *)malloc(sizeof(t_map) * (i + 1));
	if (map == NULL)
		return (NULL);
	j = 0;
	fill_map_point(0, 0, 0, map + i);
	while (j++ < i)
		fill_map_point(j - 1, index, val[j - 1], map + j - 1);
	return (map);
}

static void	fill_map_point(int x, int y, int z, t_map *point)
{
	point->x = x;
	point->y = y;
	point->z = z;
	point->vx = 0;
	point->vy = 0;
	point->vz = 0;
}
