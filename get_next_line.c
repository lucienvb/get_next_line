/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:47:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/11/11 11:42:17 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

static char	*read_line(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_ret;

	read_ret = 1;
	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
			return (free(temp), NULL);
		buf[read_ret] = '\0';
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(temp, buf);
		if (!temp || temp[0] == '\0')
			return (free(temp), NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*temp;
	char		*line;
	int			i;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	temp = read_line(fd, temp);
	if (!temp)
		return (NULL);
	i = 0;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i] == '\n')
		line = ft_substr(temp, 0, ++i, 0);
	else
		line = ft_substr(temp, 0, i, 0);
	if (!line)
		return (free(temp), NULL);
	temp = ft_substr(temp, i, (ft_strlen(temp) - i), 1);
	if (!temp)
		return (NULL);
	return (line);
}

#include <stdio.h>
int	main(void)
{
	int		fd;
	char	*test;
	
	fd = open("cheese.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	//printf("fd return: %d\n", fd);
	test = get_next_line(fd);
	while (test)
	{
		printf("%s", test);
		free(test);
		test = get_next_line(fd);
	}
	close(fd);
	return (0);
}
