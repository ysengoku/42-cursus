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

static char	*ft_fill_linebuffer(int fd, char *tmp);
static char	*ft_set_line(char *tmp);

char *get_next_line(int fd)
{
	static char	*tmp;
	char		*line;
	char		*buf;

	if (!fd)
		return (NULL);	
	tmp = ft_fill_linebuffer(fd, tmp);
	line = ft_set_line(tmp);
	tmp = ft_strchr(tmp, '\n');
	return(line);
}

static char	*ft_fill_linebuffer(int fd, char *tmp)
{
	char	buf[BUFSIZE];
	
	if (read(fd, buf, BUFSIZE) > 0)
	 {	
		while (ft_strchr(buf, '\n') == NULL)
		{
				tmp = ft_strjoin(tmp, buf);
				read(fd, buf, BUFSIZE);
		}
		tmp = ft_strjoin(tmp, buf); 
	 }
	return (tmp);
}

static char	*ft_set_line(char *tmp)
{
	int		i;
	char	*line;
	
	i = 0;
	if (tmp)
	{
		while(tmp[i] != '\n' && tmp[i] != '\0')
			i++;
		line = malloc(sizeof(char) * (i + 1));
		i = 0;
		while(tmp[i] != '\n' && tmp[i] != '\0')
		{
			line[i] = tmp[i];
			i++;
		}
		line[i] = '\0';
		return (line);
	}
	return (NULL);
}


