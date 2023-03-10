/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:41 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:17:41 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*p_dest;
	const unsigned char	*p_src;

	p_dest = (unsigned char *)dest;
	p_src = (const unsigned char *)src;
	if (n != 0)
	{
		if (dest < src)
		{
			while (n-- > 0)
				*p_dest++ = *p_src++;
		}
		else if (dest > src)
		{
			p_dest += n - 1;
			p_src += n - 1;
			while (n-- > 0)
				*p_dest-- = *p_src--;
		}
	}
	return (dest);
}
