/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:16:07 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/02 21:40:23 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c);
/* static int	check_overflow(long long num, int np);
*/

int	ft_atoi(const char *nptr)
{
	int			np;
	long long	ans;

	np = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			np = -1;
		nptr++;
	}
	ans = 0;
	while (ft_isdigit(*nptr))
	{
		ans = ans * 10 + (*nptr - '0');
		nptr++;
	}
	return ((int)(ans * np));
}

/*
		if (check_overflow(ans, np))
			return (check_overflow);
static int	check_overflow(long long num, int np)
{

}
*/

static int	ft_isspace(int c)
{
	return (('\t' <= c && c <= '\r') || c == ' ');
}
/*
#include <stdio.h>
int main()
{
	printf("%d", ft_atoi("123"));
}
*/
