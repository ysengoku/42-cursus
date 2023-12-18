/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:28 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/18 14:19:58 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_store_buf(int fd, char *stash);
static char	*ft_initialize_buf(size_t buf_size, size_t size);
static char	*ft_append_buf(char *stash, char *buf);
static char	*ft_truncate_line(char *line);

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
		return (NULL);
	line = ft_store_buf(fd, stash);
	if (!line)
		return (NULL);
	stash = ft_truncate_line(line);
	return (line);
}

static char	*ft_store_buf(int fd, char *stash)
{
	char	*buf;
	ssize_t	read_size;

	read_size = 1;
	buf = ft_initialize_buf(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size == 0)
			break ;
		stash = ft_append_buf(stash, buf);
	}
	return (free(buf), stash);
}

static char	*ft_initialize_buf(size_t buf_size, size_t size)
{
	char	*buf;
	size_t	i;

	buf = malloc((buf_size + 1) * size);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < (buf_size + 1) * size)
		buf[i++] = '\0';
	return (buf);
}

static char	*ft_append_buf(char *stash, char *buf)
{
	char	*tmp;

	if (!stash)
	{
		stash = ft_strdup("");
		if (!stash)
			return (NULL);
	}
	tmp = stash;
	stash = ft_strjoin(tmp, buf);
	free(tmp);
	if (!stash)
		return (NULL);
	return (stash);
}

static char	*ft_truncate_line(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i);
	if (!tmp)
	{
		free(line);
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}
