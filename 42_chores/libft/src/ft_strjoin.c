/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:46 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:15 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	char	*tmp_r;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	re = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (re == NULL)
		return (NULL);
	tmp_r = re;
	while (*s1)
		*tmp_r++ = *s1++;
	while (*s2)
		*tmp_r++ = *s2++;
	*tmp_r = '\0';
	return (re);
}
