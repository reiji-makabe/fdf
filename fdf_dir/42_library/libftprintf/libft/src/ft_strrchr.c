/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:49 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/31 15:33:00 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char		cc;
	const char	*tmp_s;

	cc = (char)c;
	tmp_s = (const char *)s;
	while (*tmp_s)
		tmp_s++;
	while (*tmp_s != cc && tmp_s != s)
		tmp_s--;
	if (*tmp_s == cc)
		return ((char *)tmp_s);
	else
		return (NULL);
}
