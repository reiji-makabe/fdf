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
static void		*free_and_return_null(void *subject);
static void		free_remain_row_and_map(t_map **re, int row);

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
			free_and_return_null(txt);
		re[row] = NULL;
		return (re);
	}
	if (re == NULL)
		free_and_return_null(txt);
	re[row] = fill_map_row(txt, row);
	free(txt);
	if (re[row] == NULL)
	{
		free_remain_row_and_map(re, row);
		return (NULL);
	}
	return (re);
}

static t_map	*fill_map_row(char *txt, int index)
{
	char	*val;
	size_t	i;
	size_t	j;
	t_map	*row;

	val = ft_split(txt, ' ');
	i = 0;
	while (val[i] != NULL)
		i++;
	row = (t_map *)malloc(sizeof(t_map) * (i + 1));
	if (map == NULL)
		return (NULL);
	j = 0;
	fill_map_point(0, 0, "0", row + i);
	(row + i)->end = 1;
	while (j++ < i)
		fill_map_point(j - 1, index, val[j - 1], row + j - 1);
	free(val);
	return (row);
}

static void		*free_and_return_null(void *subject)
{
	free(subject);
	return (NULL);
}

static void		free_remain_row_and_map(t_map **re, int row)
{
	row++;
	while (re[row] != NULL)
	{
		free(re[row]);
		row++;
	}
	free(re);
}
