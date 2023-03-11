/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:43 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:12 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursive_putnbr(long long tmp_n, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	long long	tmp_n;

	tmp_n = n;
	if (tmp_n < 0)
	{
		tmp_n *= -1;
		write (fd, "-", 1);
	}
	recursive_putnbr(tmp_n, fd);
}

static void	recursive_putnbr(long long tmp_n, int fd)
{
	char	nbr;

	nbr = tmp_n % 10 + '0';
	if (tmp_n < 10)
		write(fd, &nbr, 1);
	else
	{
		recursive_putnbr(tmp_n / 10, fd);
		write(fd, &nbr, 1);
	}
}
