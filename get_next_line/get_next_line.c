/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:07:28 by yusengok          #+#    #+#             */
/*   Updated: 2023/12/11 16:11:38 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h> /////////////////////////////////////////////

static char	*ft_store_buf(int fd, char *stash);
static char	*ft_set_line(char *tmp);

char *get_next_line(int fd)
{
	static char	*stash;
	char		*line;
//	char		*buf;

	if (fd < 0 || BUFSIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
// ------ read & store in line --------------------------------------
	line = ft_store_buf(fd, stash);
// ------ extract the part before \n & store the rest in stash ----------
	stash = ft_set_line(line);
	return(line);
}

static char	*ft_store_buf(int fd, char *stash)
{
	char	*buf;
	char	*tmp;
	int		read_size;

	buf = malloc((BUFSIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	read_size = 1;
	while (ft_strchr(buf, '\n') == NULL && read_size > 0)
	{
		read_size = read(fd, buf, BUFSIZE);
		if (read_size == 0)
			break;
		buf[read_size] = '\0';	
		if (stash == NULL)
			stash = ft_strdup("");
		tmp = stash;
		stash = ft_strjoin(tmp, buf);
		free(tmp);
	 }
	free(buf);
	return (stash);
}

static char	*ft_set_line(char *line)
{
	int		i;
	char	*tmp;
	
	i = 0;
	if (line)
	{
		while(line[i] != '\n' && line[i] != '\0')
			i++;
		tmp = ft_substr(line, i + 1, ft_strlen(line - i));
		line[i] = '\0';	
		return (tmp);
	}
	return (NULL);
}


