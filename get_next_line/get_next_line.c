/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:28 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/12 16:32:47 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_initialize_buf(char *buf);
static char	*ft_store_buf(int fd, char *stash);
static char	*ft_truncate_line(char *line);

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFSIZE <= 0 || read(fd, &line, 0) < 0)
	{
		free(stash);
		return (NULL);
	}
	line = ft_store_buf(fd, stash);
	if (!line)
	{
		free(stash);
		return (NULL);
	}
	stash = ft_truncate_line(line);
	return (line);
}

static void	ft_initialize_buf(char *buf)
{
	unsigned long	i;

	i = 0;
	while (i < (BUFSIZE + 1) * sizeof(char))
		buf[i++] = '\0';
}

static char	*ft_store_buf(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		read_size;

	buf = malloc((BUFSIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	ft_initialize_buf(buf);
	read_size = 1;
	while (!ft_strchr(buf, '\n') && read_size > 0)
	{
		read_size = read(fd, buf, BUFSIZE);
		buf[read_size] = '\0';
		if (read_size == 0)
			break ;
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
	}
	free(buf);
	return (stash);
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
