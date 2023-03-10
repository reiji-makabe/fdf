/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:40 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:04 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*us;
	unsigned char		uc;

	us = (const unsigned char *)s;
	uc = (unsigned char)c;
	if (n == 0)
		return (NULL);
	while (n-- && *us != uc)
		us++;
	if (++n == 0)
		return (NULL);
	else
		return ((void *)us);
}
