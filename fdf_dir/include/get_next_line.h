/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:38:56 by rmakabe           #+#    #+#             */
/*   Updated: 2023/04/15 02:01:43 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4200
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
void	*gnl_calloc(size_t nmemb, size_t size);
char	*gnl_strjoin(char const *s1, char const *s2);
size_t	gnl_strlen(const char *s);

#endif
