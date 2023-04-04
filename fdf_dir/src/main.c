/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 17:14:34 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/17 08:18:09 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static int	safe_open(char *file, int aut);

int	main(int argc, char *argv[])
{
	int		fd;
	t_map	**map;

	if (argc != 2)
		exit (1);
	fd = safe_open(argv[1], O_RDONLY);
	map = create_map(fd);
	draw_map(map);
}

static int	safe_open(char *file, int aut)
{
	int	fd;

	errno = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(errno);
	}
	return (fd);
}
