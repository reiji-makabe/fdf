/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 04:17:44 by rmakabe           #+#    #+#             */
/*   Updated: 2023/03/13 19:42:29 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_and_conversion_strings(char *tmp_s, size_t len, char c);
static int		put_in_strings(char *tmp_s, char **re, size_t num_strings);

char	**ft_split(char const *s, char c)
{
	char	**re;
	char	*tmp_s;
	size_t	num_strings;

	if (s == NULL)
		return (NULL);
	tmp_s = ft_strdup(s);
	if (tmp_s == NULL)
		return (NULL);
	num_strings = check_and_conversion_strings(tmp_s, ft_strlen(s), c);
	re = (char **)malloc(sizeof(char *) * (num_strings + 1));
	if (re == NULL)
		return (NULL);
	if (put_in_strings(tmp_s, re, num_strings))
		free_2d_array(re);
	free(tmp_s);
	return (re);
}

static size_t	check_and_conversion_strings(char *tmp_s, size_t len, char c)
{
	size_t	re;
	int		flag_start;

	re = 0;
	flag_start = 1;
	while (len--)
	{
		if (*tmp_s == c)
		{
			flag_start = 1;
			*tmp_s = '\0';
		}
		else if (*tmp_s != c)
		{
			if (flag_start)
				re++;
			flag_start = 0;
		}
		tmp_s++;
	}
	return (re);
}

static int	put_in_strings(char *tmp_s, char **re, size_t num_strings)
{
	size_t	len_sp_word;
	size_t	index;
	size_t	index_re;
	size_t	return_num;

	index_re = 0;
	return_num = 0;
	while (num_strings--)
	{
		while (*tmp_s == '\0')
			tmp_s++;
		len_sp_word = ft_strlen(tmp_s);
		re[index_re] = (char *)malloc(len_sp_word + 1);
		if (*re == NULL)
			return_num = 1;
		index = 0;
		while (index < len_sp_word)
			re[index_re][index++] = *tmp_s++;
		re[index_re][index] = '\0';
		index_re++;
	}
	re[index_re] = NULL;
	return (return_num);
}

void	free_2d_array(char **re)
{
	int		index;

	if (re)
	{
		index = 0;
		while (re[index] != NULL)
			free(re[index++]);
		free(re);
		re = NULL;
	}
}
