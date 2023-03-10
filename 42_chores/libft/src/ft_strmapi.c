/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:47 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 05:42:04 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*re;
	size_t			len_s;
	unsigned int	index;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	re = (char *)malloc(len_s + 1);
	if (re == NULL)
		return (NULL);
	re[len_s] = '\0';
	index = 0;
	if (f != NULL && s[index])
	{
		while (index < len_s)
		{
			re[index] = f(index, s[index]);
			index++;
		}
	}
	return (re);
}
