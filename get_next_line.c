/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_v3.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 14:47:43 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/10/29 15:33:13 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stddef.h>
#include "get_next_line.h"

static char	*read_line(int fd, char *temp)
{
	char	buf[BUFFER_SIZE + 1];
	int		read_ret;

	read_ret = 1;
	while (!ft_strchr(temp, '\n') && read_ret != 0)
	{
		read_ret = read(fd, buf, BUFFER_SIZE);
		if (read_ret == -1)
		{
			return (NULL);
		}
		buf[read_ret] = '\0';
	//	printf("count: ");
	//	printf("%i\n", read_ret);
		if (!temp)
			temp = ft_strdup(buf);
		else
			temp = ft_strjoin(temp, buf);
	}
	if (read_ret == 0)
		return (NULL);
	return (temp);
}

char *get_next_line(int fd)
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
	line = ft_substr(temp, 0, ++i);
	temp = ft_substr(temp, i, (ft_strlen(temp) - i));
	return (line);
}

int	main(void)
{
	int		fd;
	int		i;
	char	*test;
	
	fd = open("bacon.txt", O_RDONLY);
	if (fd == -1)
		return (0);
	test = get_next_line(fd);
	i = 0;
	while (test != NULL)
	{
		printf("%s", test);
		free(test);
		test = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
