#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// INCLUDE
# include <stddef.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

// DEFINE
# if BUFFER_SIZE < 1 || BUFFER_SIZE >= 10000000
#  undef BUFFER_SIZE
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

// GET_NEXT_LINE
char	*get_next_line(int fd);

// UTILS
void	*gnl_memcpy(void *dst, const char *src, size_t n);
char	*gnl_strdup(char *s1);
char	*gnl_substr(char *s, unsigned int start, size_t len, int free_s);
int		gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
char	*gnl_strchr(const char *s, int c);

#endif
