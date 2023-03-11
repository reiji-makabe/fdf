/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:03 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/10 02:31:33 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	const size_t	over = 0 - 1;
	void			*re;

	if (nmemb == 0 || size == 0)
	{
		nmemb = 1;
		size = 1;
	}
	if ((over / nmemb) < size)
		return (NULL);
	re = malloc(nmemb * size);
	if (re)
		ft_bzero(re, nmemb * size);
	return (re);
}
// to do error number
