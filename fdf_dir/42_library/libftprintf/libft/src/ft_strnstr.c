/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:48 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/07 00:46:19 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_needl(const char *h, const char *n, size_t len);

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	if (ft_strlen(n) == 0)
		return ((char *)h);
	if (len < ft_strlen(n))
		return (NULL);
	if (h == n)
		return ((char *)h);
	while (len && *h)
	{
		if (*h == *n)
			if (check_needl(h, n, len))
				return ((char *)h);
		h++;
		len--;
	}
	return (NULL);
}

static int	check_needl(const char *h, const char *n, size_t len)
{
	size_t		i;

	i = 0;
	while (*h == *n && *n != '\0' && i < len)
	{
		n++;
		h++;
		i++;
	}
	if (*n == '\0')
		return (1);
	return (0);
}
