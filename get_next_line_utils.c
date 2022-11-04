/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 09:39:03 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/10/29 15:02:59 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	temp = malloc((size + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		temp[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		temp[i + j] = s2[j];
		j++;
	}
	temp[i + j] = '\0';
	return (temp);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char) c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char) c == '\0')
		return ((char *)s);
	return (NULL);
}

void	*ft_memcpy(void *dst, const char *src, size_t n)
{
	char	*dest;
	char	*source;

	if (!dst && !src)
		return (0);
	dest = dst;
	source = (char *)src;
	while (n > 0)
	{
		*dest = *source;
		dest++;
		source++;
		n--;
	}
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dup;
	char	*temp;
	int		strsize;

	strsize = ft_strlen(s1);
	dup = malloc((strsize + 1) * sizeof(char));
	if (!dup)
		return (0);
	temp = dup;
	while (*s1)
	{
		*temp = *s1;
		temp++;
		s1++;
	}
	dup[strsize] = '\0';
	return (dup);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	len_str;
	size_t	var;

	if (!s)
		return (NULL);
	len_str = ft_strlen(s);
	var = len_str - start;
	if ((size_t) start >= len_str)
		return (ft_strdup(""));
	if (len > var)
		len = var;
	p = malloc((len + 1) * sizeof(char));
	if (!p)
		return (NULL);
	ft_memcpy(p, &(s[start]), len);
	p[len] = '\0';
	return (p);
}
