#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen(const char *c);
char	*ft_strchr(const char *str, int c);
char	*ft_strnjoin(char *from, char const *to, size_t len_of_to);
char	*get_next_line(int fd);
char	*ft_strdup(const char *restrict src, size_t size);

#endif
