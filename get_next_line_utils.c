/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeskim <haeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:31:51 by haeskim           #+#    #+#             */
/*   Updated: 2023/01/05 20:09:36 by haeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	new_c;
	char	*new_s;

	i = 0;
	new_c = (char)c;
	new_s = (char *)s;
	if (!s)
		return (0);
	while (new_s[i])
	{
		if (new_s[i] == new_c)
			return (&new_s[i]);
		i++;
	}
	if (new_s[i] == new_c)
		return (&new_s[i]);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	i;
	size_t	s1_len;

	s1_len = 0;
	while (*(s1 + s1_len))
		s1_len++;
	ptr = (char *)malloc(sizeof(char) * (s1_len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	length;
	char	*ptr;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc(sizeof(char) * (length + 1));
	if (!ptr)
		return (0);
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}
