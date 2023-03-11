/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:49 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/08 14:23:55 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_set(char c, const char *set);
static int	check_set_back(char c, const char *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	index;
	size_t	index_back;

	if (s1 == NULL)
		return (NULL);
	index = 0;
	while (check_set(s1[index], set))
		index++;
	index_back = 0;
	while (s1[index_back] != '\0')
		index_back++;
	while (check_set_back(s1[index_back], set))
		index_back--;
	return (ft_substr(s1, index, index_back - index + 1));
}

static int	check_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	check_set_back(char c, const char *set)
{
	size_t		len;

	len = ft_strlen(set) + 1;
	while (*set)
		set++;
	while (len--)
	{
		if (c == *set)
			return (1);
		set--;
	}
	return (0);
}
