/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:44 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/31 15:32:39 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char		cc;
	const char	*re;

	cc = (char)c;
	re = (const char *)s;
	while (*re != cc && *re != '\0')
		re++;
	if (*re == cc)
		return ((char *)re);
	else
		return (NULL);
}
