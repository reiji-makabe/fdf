/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmakabe <rmkabe012@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 17:39:45 by rmakabe           #+#    #+#             */
/*   Updated: 2022/11/16 04:28:06 by rmakabe          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_until_getnewline(int fd, char *buf);
static char	*return_one_line(char *buf);
static char	*restart_buf(char *buf);
static int	check_new_line(char *buf);

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buf = read_until_getnewline(fd, buf);
	if (!buf)
		return (NULL);
	line = return_one_line(buf);
	buf = restart_buf(buf);
	return (line);
}

// if gnl_strjoin received a NULL, it interprets the NULL as an empty strings.
// Same as above regarding check_new_line and gnl_strlen.
static char	*read_until_getnewline(int fd, char *buf)
{
	char	*read_from_fd;
	char	*next_buf;

	while (!check_new_line(buf))
	{
		read_from_fd = (char *)gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!read_from_fd)
			return (NULL);
		if (read(fd, read_from_fd, BUFFER_SIZE) <= 0)
		{
			free(read_from_fd);
			read_from_fd = NULL;
			return (buf);
		}
		next_buf = gnl_strjoin(buf, read_from_fd);
		free(read_from_fd);
		read_from_fd = NULL;
		free(buf);
		buf = next_buf;
		if (!buf)
			return (NULL);
	}
	return (buf);
}

static char	*return_one_line(char *buf)
{
	size_t	index;
	char	*re;

	if (!buf)
		return (NULL);
	index = 0;
	while (buf[index] != '\n' && buf[index] != '\0')
		index++;
	if (buf[index] == '\n')
		index++;
	re = (char *)gnl_calloc(index + 1, sizeof(char));
	if (!re)
		return (NULL);
	while (index-- > 0)
		re[index] = buf[index];
	return (re);
}

static char	*restart_buf(char *buf)
{
	char	*tmp_buf;
	char	*next_buf;
	char	*tmp_next;

	tmp_buf = buf;
	while (*tmp_buf != '\n' && *tmp_buf != '\0')
		tmp_buf++;
	if (*tmp_buf == '\n')
		tmp_buf++;
	if (*tmp_buf == '\0')
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	next_buf = (char *)gnl_calloc(gnl_strlen(tmp_buf) + 1, sizeof(char));
	if (!next_buf)
		return (NULL);
	tmp_next = next_buf;
	while (*tmp_buf)
		*tmp_next++ = *tmp_buf++;
	free(buf);
	buf = next_buf;
	return (next_buf);
}

static int	check_new_line(char *buf)
{
	if (buf != NULL)
	{
		while (*buf)
		{
			if (*buf == '\n')
				return (1);
			buf++;
		}
	}
	return (0);
}
