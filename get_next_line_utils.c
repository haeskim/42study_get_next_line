/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haeskim <haeskim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 12:31:51 by haeskim           #+#    #+#             */
/*   Updated: 2022/12/29 15:20:10 by haeskim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
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

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*new_src;
	char		*new_dst;

	i = 0;
	new_src = (const char *)src;
	new_dst = (char *)dst;
	if (!dst && !src)
		return (0);
	while (i < n)
	{
		*(new_dst + i) = *(new_src + i);
		i++;
	}
	return (new_dst);
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
	return (ptr);
	ptr[i] = '\0';
}
