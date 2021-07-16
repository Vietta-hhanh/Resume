#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>

char							*ft_strchr(const char *s, int c);
size_t							ft_strlen(const char *s);
char							*ft_strjoinhelp(char const *s2);
char							*ft_strjoin(char const *s1, char const *s2);
char							*ft_strdup(const char *s1);
char							*ft_check(char **remain, char **line);
int								get_next_line(int fd, char **line);
int								ft_loop(char **line, char **remain,
int writtenbytes, int fd);
#endif
