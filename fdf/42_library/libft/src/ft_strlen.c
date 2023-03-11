/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:47 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/27 04:17:47 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	ans;

	ans = 0;
	while (*s++)
		ans++;
	return (ans);
}

//#include <stdio.h>
//int	main(void)
//{
//	char	string[100] = "Hello, World!";
//	printf("%d", ft_strlen(string));
//}
