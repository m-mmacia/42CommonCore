#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

char			*get_next_line(int fd);
int				ft_strlen(const char *str);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strchr(const char *s, int i);
char			*ft_strdup(const char *s);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strcpy(char *dest, char *src);

#endif
