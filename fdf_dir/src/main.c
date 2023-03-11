/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:29:29 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/12 02:32:37 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * errornumber(errno) to do
 */
#include "libft.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <errno.h>
#include <stdio.h>

int	main(int argc, char *argv[])
{
//	int	fd;
//	char	*test;
//
//	if (argc != 2)
//		exit(1);
//	errno = 0;
//	fd = open(argv[1], O_RDONLY);
//	if (fd < 0)
//	{
//		perror("Error:");
//		exit(errno);
//	}
//	else
//	{
//		test = get_next_line(fd);
//		while (test)
//		{
//			test = get_next_line(fd);
//			printf("%s", test);
//		}
//	}
	printf("%d, %s, ba-kaba-ka\n", argc, argv[1]);
}
