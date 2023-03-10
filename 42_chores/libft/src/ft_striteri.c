/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:45 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:19:15 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	index;
	size_t	len_s;

	if (s)
	{
		index = 0;
		len_s = ft_strlen(s);
		while (f != NULL && index < len_s)
		{
			f(index, &s[index]);
			index++;
		}
	}
}
