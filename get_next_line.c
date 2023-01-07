/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeskim <haeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:47:50 by haeskim           #+#    #+#             */
/*   Updated: 2023/01/06 17:38:12 by haeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

char	*make_line(char *buf, char **line, char *remain)
{
	int		i;
	int		j;
	char	tmp_line[BUFFER_SIZE + 1];

	i = 0;
	while (buf[i] && buf[i] != '\n')
	{
		tmp_line[i] = buf[i];
		i++;
	}
	tmp_line[i] = buf[i];
	i++;
	tmp_line[i] = 0;
	*line = after_read_process(line, tmp_line);
	if (!(*line))
		return (0);
	j = 0;
	if (buf[i - 1] == '\n')
	{
		while (buf[i])
			remain[j++] = buf[i++];
		remain[j] = 0;
	}
	return (*line);
}

char	*read_process(int read_size, int fd, char *buf, char **line)
{
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size <= -1)
		{
			free(*line);
			return (0);
		}
		buf[read_size] = 0;
		if (ft_strchr(buf, '\n') || read_size < BUFFER_SIZE)
			break ;
		*line = after_read_process(line, buf);
		if (!(*line))
			return (0);
	}
	if (read_size == 0)
	{
		if (!(*line[0]))
		{
			free(*line);
			return (0);
		}
		return (*line);
	}
	return (*line);
}

char	*remain_to_line(char *remain, char **line)
{
	char	tmp_line[BUFFER_SIZE + 1];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (remain[i] && remain[i] != '\n')
	{
		tmp_line[i] = remain[i];
		i++;
	}
	tmp_line[i] = remain[i];
	i++;
	tmp_line[i] = 0;
	while (remain[i])
	remain[j++] = remain[i++];
	remain[j] = 0;
	free(*line);
	*line = ft_strdup(tmp_line);
	return (*line);
}

char	*if_remain_exists(char *remain, char **line)
{
	if (ft_strchr(remain, '\n'))
		return (remain_to_line(remain, line));
	free (*line);
	*line = ft_strdup(remain);
	if (!(*line))
		return (0);
	remain[0] = 0;
	return (*line);
}

char	*get_next_line(int fd)
{
	static char	remain[BUFFER_SIZE + 1];
	char		buf[BUFFER_SIZE + 1];
	char		*line;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = (char *)malloc(sizeof(char));
	if (!line)
		return (0);
	line[0] = 0;
	if (remain[0])
	{
		line = if_remain_exists(remain, &line);
		if (!line)
			return (0);
	}
	if (ft_strchr(line, '\n'))
		return (line);
	read_size = 1;
	if (!read_process(read_size, fd, buf, &line))
		return (0);
	if (read_size == 0)
		return (line);
	return (make_line(buf, &line, remain));
}
