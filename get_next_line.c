/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeskim <haeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:47:50 by haeskim           #+#    #+#             */
/*   Updated: 2023/01/06 10:58:06 by haeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			j;
	int			read_size;
	char		*tmp;
	char		tmp2[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (0);
	line[0] = 0;
	if (remain[0])
	{
		i = 0;
		j = 0;
		if (ft_strchr(remain, '\n'))
		{
			while (remain[i] && remain[i] != '\n')
			{
				tmp2[i] = remain[i];
				i++;
			}
			tmp2[i] = remain[i];
			i++;
			tmp2[i] = 0;
			while (remain[i])
				remain[j++] = remain[i++];
			remain[j] = 0;
			free(line);
			line = ft_strdup(tmp2);
			return (line);
		}
		free (line);
		line = ft_strdup(remain);
		if (!line)
			return (0);
		remain[0] = 0;
	}
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= -1)
		{
			if (line)
				free(line);
			return (0);
		}
		buf[read_size] = 0;
		if (ft_strchr(buf, '\n') || read_size < BUFFER_SIZE || !buf[0])
			break ;
		if (!line[0])
		{	
			free(line);
			line = ft_strdup(buf);
			if (!line)
				return (0);
		}
		else
		{
			tmp = line;
			line = ft_strjoin(line, buf);
			if (!line)
			{
				free(tmp);
				return (0);
			}
			free(tmp);
		}
	}
	if (read_size == 0)
	{
		if (!line[0])
		{
			free(line);
			return (0);
		}
		return (line);
	}
	i = 0;
	if (read_size < BUFFER_SIZE)
	{
		while (buf[i] && buf[i] != '\n')
		{
			tmp2[i] = buf[i];
			i++;
		}
		tmp2[i] = buf[i];
		i++;
		tmp2[i] = 0;
		if (!line[0])
		{
			free(line);
			line = ft_strdup(tmp2);
			if (!line)
				return (0);
		}
		else
		{
			tmp = line;
			line = ft_strjoin(line, tmp2);
			if (!line)
			{
				free(tmp);
				return (0);
			}
			free(tmp);
		}
		j = 0;
		if (buf[i - 1] == '\n')
		{
			while (buf[i])
			{
				remain[j++] = buf[i++];
			}
			remain[j] = 0;
		}
		return (line);
	}
	while (buf[i] && buf[i] != '\n')
	{
		tmp2[i] = buf[i];
		i++;
	}
	tmp2[i] = buf[i];
	i++;
	tmp2[i] = 0;
	if (!line[0])
	{
		free(line);
		line = ft_strdup(tmp2);
		if (!line)
			return (0);
	}
	else
	{
		tmp = line;
		line = ft_strjoin(line, tmp2);
		if (!line)
		{
			free(tmp);
			return (0);
		}
		free(tmp);
	}
	j = 0;
	while (buf[i])
	{
		remain[j++] = buf[i++];
	}
	remain[j] = 0;
	return (line);
}
