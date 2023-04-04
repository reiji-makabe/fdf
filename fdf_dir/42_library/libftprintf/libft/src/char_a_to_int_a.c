/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_a_to_int_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 00:15:57 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/14 00:22:06 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*char_a_to_int_a(char *char_a, size_t *size)
{
	char	**char_2d;
	char	**tmp;
	int		*re;
	int		num;

	char_2d = ft_split(char_a, ' ');
	if (char_2d == NULL)
		return (NULL);
	tmp = char_2d;
	num = 0;
	while (*tmp++)
		num++;
	re = char_2d_a_to_int_a(num, char_2d);
	*size = num;
	free_2d_array(char_2d);
	return (re);
}

int	*char_2d_a_to_int_a(int num, char **char_2d)
{
	char	*tmp;
	int		*re;
	int		flag;

	re = (int *)ft_calloc(num, sizeof(int));
	if (re == NULL)
		return (NULL);
	flag = 0;
	while (num--)
	{
		re[num] = ft_atoi(char_2d[num]);
		tmp = ft_itoa(re[num]);
		if ((ft_strlen(tmp) != ft_strlen(char_2d[num]))
			&& ft_strncmp(tmp, char_2d[num], ft_strlen(tmp)))
			flag = 1;
		free(tmp);
		if (flag)
		{
			free(re);
			re = NULL;
			break ;
		}
	}
	return (re);
}
