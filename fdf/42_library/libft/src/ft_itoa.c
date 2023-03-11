/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:20 by rmakabe           #+#    #+#             */
/*   Updated: 2022/10/31 16:31:05 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		put_recursive_itoa(long long num, size_t string_size, char *re);
static size_t	return_string_size(long long num);
static void		remove_minus(long long *tmp_n, int *np);

char	*ft_itoa(int n)
{
	long long	tmp_n;
	int			np;
	char		*string;
	size_t		string_size;

	tmp_n = n;
	np = 1;
	remove_minus(&tmp_n, &np);
	string_size = return_string_size(tmp_n);
	if (np == -1)
		string_size++;
	string = (char *)malloc(string_size + 1);
	if (string == NULL)
		return (NULL);
	string[string_size] = '\0';
	if (np == -1)
	{
		*string++ = '-';
		string_size--;
	}
	put_recursive_itoa(tmp_n, string_size - 1, string);
	if (np == -1)
		string--;
	return (string);
}

static void	remove_minus(long long *tmp_n, int *np)
{
	if (*tmp_n < 0)
	{
		*tmp_n *= -1;
		*np *= -1;
	}
}

static size_t	return_string_size(long long num)
{
	size_t	re;

	re = 1;
	while (num >= 10)
	{
		re++;
		num /= 10;
	}
	return (re);
}

static void	put_recursive_itoa(long long num, size_t string_size, char *re)
{
	if (num < 10)
		re[string_size] = (num % 10) + '0';
	else
	{
		re[string_size] = (num % 10) + '0';
		put_recursive_itoa(num / 10, string_size - 1, re);
	}
}
