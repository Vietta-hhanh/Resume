/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhanh <hhanh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 15:24:21 by hhanh             #+#    #+#             */
/*   Updated: 2021/02/22 15:21:14 by hhanh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char		*ft_strchr(const char *s, int c);
int			ft_strlen(const char *s);
char		*ft_strjoinhelp(char const *s2);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strdup(const char *s1);
char		*ft_check(char **remain, char **line);
int			get_next_line(int fd, char **line);
int			ft_loop(char **line, char **remain, int writtenbytes, int fd);
#endif
