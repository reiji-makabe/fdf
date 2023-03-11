/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:47 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:17:47 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t		len_s;
	size_t		i;

	len_s = ft_strlen(src);
	if (n != 0)
	{
		i = 0;
		while (i + 1 < n && i < len_s)
		{
			*dest++ = *src++;
			i++;
		}
		*dest = '\0';
	}
	return (len_s);
}
