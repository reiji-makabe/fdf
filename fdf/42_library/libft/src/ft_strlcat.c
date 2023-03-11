/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:46 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/08 14:55:14 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if (dest == NULL && n == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	if (len_dest >= n)
		return (n + len_src);
	else
	{
		while (*dest)
			dest++;
		i = 0;
		while (i++ < n - len_dest - 1 && *src)
			*dest++ = *src++;
		*dest = '\0';
	}
	return (len_dest + len_src);
}
// #include <stdio.h>
// int main()
// {
// 	char	dest[20] = "abcde";
// 	char	src[] = "123";
// 	int		n = -1;
// 	
// 	size_t	result = ft_strlcat(dest, src, n);
// 	printf("%s : %lu\n", dest, result);
// }
