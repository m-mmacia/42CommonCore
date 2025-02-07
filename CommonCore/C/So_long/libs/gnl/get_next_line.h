
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <string.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int	        ft_strlen_gnl(const char *str);

char		*newline(char **stash);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(const char *s);
char		*ft_strchr(const char *s, int i);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*get_next_line(int fd);
char		*line_extract(char *line);

#endif
