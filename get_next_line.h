/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-bus <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 09:45:33 by lvan-bus      #+#    #+#                 */
/*   Updated: 2022/11/10 09:30:15 by lvan-bus      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// INCLUDE
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
//# include <sys/types.h>
//# include <sys/uio.h>
//# include <limits.h>

// DEFINE
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);

// UTILS
void	*ft_memcpy(void *dst, const char *src, size_t n);
char	*ft_strdup(char *s1);
char	*ft_substr(char *s, unsigned int start, size_t len, int free_s);
int		ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

#endif
