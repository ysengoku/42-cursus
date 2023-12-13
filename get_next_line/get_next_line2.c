/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:28 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/13 15:29:37 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> ///////////////////////////////////////////////////

static char	*ft_initialize(size_t size);
static char	*ft_store_buf(int fd, char *stash);
static char	*ft_truncate_line(char *stash, char *line);

char	*get_next_line(int fd)
{
	static char	*stash = NULL;
	char		*line;
	size_t		i;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, &line, 0) < 0)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = ft_store_buf(fd, stash);
	printf("stash: %s\n", stash); ///// stash = なしだとstashはnullになる。あるとAbort trap: 6
	if (!stash)
	{
		free(stash);
		return (NULL);
	}
	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	line = ft_initialize(i);
	if (!line)
		return (NULL);
	ft_truncate_line(stash, line);
	return (line);
}

static char	*ft_initialize(size_t size)
{
	char	*buf;
	size_t	i;

	buf = malloc(size);
	if (!buf)
		return (NULL);
	i = 0;
	while (i < size)
		buf[i++] = '\0';
	return (buf);
}

static char	*ft_store_buf(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		read_size;

	read_size = 1;
	while (!ft_strchr(stash, '\n') && read_size > 0)
	{
		buf = ft_initialize((BUFFER_SIZE + 1) * sizeof(char));
		if (!buf)
			return (NULL);
		read_size = read(fd, buf, BUFFER_SIZE);
		buf[read_size] = '\0';
		if (read_size < 0)
			return (free(buf), NULL);
		if (read_size == 0)
			return (free(buf), stash);
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
		free(buf);
	}
	return (stash);
}

static char	*ft_truncate_line(char *stash, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	if (stash[i] == '\0' || stash[i + 1] == '\0')
		return (NULL);
	tmp = ft_substr(stash, i + 1, ft_strlen(stash) - i);
	if (!tmp)
		return (free(stash), NULL);
	free(stash);
	stash = ft_strdup(tmp);
	free(tmp);
	return (stash);
}
