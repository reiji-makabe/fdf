/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:49 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 18:44:58 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	return_min(size_t remain, size_t len);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	char	*tmp_r;
	size_t	len_s;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_strdup(""));
	re = (char *)malloc(return_min((len_s + 1 - start), len + 1));
	if (re == NULL)
		return (NULL);
	tmp_r = re;
	while (start--)
		s++;
	while (len-- && *s)
		*tmp_r++ = *s++;
	*tmp_r = '\0';
	return (re);
}

static size_t	return_min(size_t remain, size_t len)
{
	if (remain <= len)
		return (remain);
	return (len);
}
