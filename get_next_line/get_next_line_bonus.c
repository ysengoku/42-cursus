/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:00:27 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/13 16:14:16 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_initialize_buf(size_t buf_size, size_t size);
static char	*ft_store_buf(int fd, char **stash);
static char	*ft_truncate_line(char *line);

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free(stash[fd]);
		stash[fd] = NULL;
		return (NULL);
	}
	line = ft_store_buf(fd, &stash[fd]);
	if (!line)
	{
		free(line);
		free(stash[fd]);
		stash[fd] = NULL;		
		return (NULL);
	}
	stash[fd] = ft_truncate_line(line);
	return (line);
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

static char	*ft_store_buf(int fd, char **stash)
{
	char	*buf;
	char	*tmp;
	int		read_size;

	buf = ft_initialize_buf(BUFFER_SIZE, sizeof(char));
	if (!buf)
		return (NULL);
	read_size = 1;
	while (!ft_strchr(buf, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size < 0)
			return (free(buf), NULL);
		if (read_size == 0)
			break ;
		if (stash[fd] == NULL)
			stash[fd] = ft_strdup("");
		tmp = stash[fd];
		stash[fd] = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (stash[fd]);
}

static char	*ft_truncate_line(char *line_buf)
{
	int		i;
	char	*tmp;

	i = 0;
	if (line_buf)
	{
		while (line_buf[i] != '\n' && line_buf[i] != '\0')
			i++;
		if (line_buf[i] == '\0' || line_buf[i + 1] == '\0')
			return (NULL);
		tmp = ft_substr(line_buf, i + 1, ft_strlen(line_buf) - i);
		if (!tmp)
			{
				free(line_buf);
				return (NULL);
			}
		line_buf[i + 1] = '\0';
		return (tmp);
	}
	free(line_buf);
	return (NULL);
}
