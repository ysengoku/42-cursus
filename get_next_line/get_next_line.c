/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:28 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/19 15:24:42 by yusengok         ###   ########.fr       */
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
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	line = ft_store_buf(fd, stash); // malloc fail chk - OK
	if (!line)
		return (NULL);
	stash = ft_truncate_line(line); // malloc fail chk - OK
	return (line);
}

static char	*ft_store_buf(int fd, char *stash)
{
	char	*buf;
	ssize_t	read_size;

	read_size = 1;
	buf = ft_initialize_buf(BUFFER_SIZE, sizeof(char)); // malloc fail chk -ok
	if (!buf)
		return (NULL);
	while (!ft_strchr(buf, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size == 0)
			break ;
		stash = ft_append_buf(stash, buf);
		if (!stash) ////////////////////////////////
			break ; //////////////////////////////////
	}
	return (free(buf), stash);
}

static char	*ft_initialize_buf(size_t buf_size, size_t size)
{
	char	*buf;
	size_t	i;

	buf = malloc((buf_size + 1) * size);  // malloc fail chk - OK
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
		stash = ft_strdup(""); // malloc fail chk - OK
		if (!stash)
			return (NULL);
	}
	tmp = stash;
	stash = ft_strjoin(tmp, buf);  // malloc fail chk - OK
	free(tmp);
	if (!stash)
		return (NULL);
	return (stash);
}

static char	*ft_truncate_line(char *line)
{
	ssize_t	i;
	char	*tmp;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[i + 1] == '\0')
		return (NULL);
	tmp = ft_substr(line, i + 1, ft_strlen(line) - i); // malloc fail chk - OK
	if (!tmp)
	{
		line = NULL;
		return (NULL);
	}
	line[i + 1] = '\0';
	return (tmp);
}
