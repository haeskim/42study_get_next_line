/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeskim <haeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 09:47:50 by haeskim           #+#    #+#             */
/*   Updated: 2022/12/29 19:25:51 by haeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	static char	*aa;//read후에 남은 애들 들어갈 자리
	char		buf[BUFFER_SIZE];
	char		*line;
	int			i;
	int			j;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!aa)
	{
		aa = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!aa)
			return (0);
	}

	line = (char *)malloc(sizeof(char));
	*line = 0;

	// line = (char *)malloc(sizeof(char));
	// if (!line)
	// {
	// 	free(aa);
	// 	return (0);
	// }
/*
	if (aa)
	{
		if (ft_strchr(aa, '\n'))
		{
			i = 0;
			j = 0;
			while (aa[i] != '\n')
			{
				line[i] = aa[i];
				i++;
			}
			line[i] = aa[i];
			i++;
			while (aa[i])
				aa[j++] = aa[i++];
			aa[j] = 0;
			return (line);
		}
		line = ft_strjoin(line, aa);
	}
*/
	if (aa)
	{
		if (ft_strchr(aa, '\n'))
		{
			i = 0;
			j = 0;
			while (aa[i] != '\n')
				i++;
			line = (char *)malloc(sizeof(char) * i);
			i = 0;
			while (aa[i] != '\n')
			{
				line[i] = aa[i];
				i++;
			}
			line[i] = aa[i];
			i++;
			while (aa[i])
				aa[j++] = aa[i++];
			aa[j] = 0;
			return (line);
		}
		line = ft_strjoin(line, aa);
	}
	read_size = 1;
	while (read_size > 0)
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (ft_strchr(buf, '\n'))
			break ;
		if (read_size <= -1)
		{
			free(aa);
			free(line);
			return (0);
		}
		line = ft_strjoin(line, buf);
	}
	if (read_size == 0)
		return (line);
	j = 0;
	while (line[j])
		j++;
	i = 0;
	while (buf[i] != '\n')
		line[j++] = buf[i++];
	line[j++] = buf[i++];
	j = 0;
	while (buf[i])
	{
		aa[j++] = buf[i++];
	}
//	aa[j] = '\0';
	return (line);
}

#include <fcntl.h>

int	main(void)
{
	char	*buf;
	int		fd;

	fd = open("/Users/haeskim/haeskim/gnl/file1.txt", O_RDONLY);
	buf = get_next_line(fd);
	printf("==1==%s", buf);
	buf = get_next_line(fd);
	printf("==2==%s", buf);
	buf = get_next_line(fd);
	printf("==3==%s", buf);
//	buf = get_next_line(fd);
//	printf("==4==%s", buf);
}