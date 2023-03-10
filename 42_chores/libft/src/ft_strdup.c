/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:45 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:14 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*re;
	char	*tmp_r;
	size_t	len_s;

	len_s = ft_strlen(s) + 1;
	re = (char *)malloc(len_s);
	if (re == NULL)
		return (NULL);
	tmp_r = re;
	while (len_s--)
		*tmp_r++ = *s++;
	return (re);
}
