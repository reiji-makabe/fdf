/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:41:53 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/24 13:42:34 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	gnl_strlen(const char *s)
{
	size_t	ans;

	ans = 0;
	if (s != NULL)
		while (*s++)
			ans++;
	return (ans);
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	size_t			over;
	size_t			num;
	void			*re;
	unsigned char	*tmp;

	over = 0 - 1;
	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((over / nmemb) < size)
		return (NULL);
	num = nmemb * size;
	re = malloc(num);
	if (re)
	{
		tmp = re;
		while (num-- > 0)
			*tmp++ = '\0';
	}
	return (re);
}

char	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*re;
	char	*tmp_r;

	re = (char *)malloc(gnl_strlen(s1) + gnl_strlen(s2) + 1);
	if (re == NULL)
		return (NULL);
	tmp_r = re;
	if (s1)
		while (*s1)
			*tmp_r++ = *s1++;
	if (s2)
		while (*s2)
			*tmp_r++ = *s2++;
	*tmp_r = '\0';
	return (re);
}
