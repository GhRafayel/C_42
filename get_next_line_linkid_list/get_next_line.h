#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <limits.h>
# include <ctype.h>
# include <unistd.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct obj{
    int id;
    char *str;
    struct obj	*next;
} MyStruct;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 40
# endif

# ifndef MAX_FD
#  define MAX_FD 256
# endif

char	*ft_strdup(const char *s1);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned start, size_t len);

size_t	ft_strlcpy(char *dest, char *src, size_t len);
size_t	ft_strlen(const char *s);

char	*get_next_line(int fd);

#endif