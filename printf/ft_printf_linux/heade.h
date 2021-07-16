#ifndef HEADE_H
# define HEADE_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_s
{
	int			ss;
	int			sc;
	int			sp;
	int			sd;
	int			si;
	int			su;
	int			sx;
	int			sbs;
	int			fm;
	int			fn;
	int			fw;
	int			fa;
	int			faa;
	int			blocker;
	int			freeflag;
	int			count;

}				t_list;

void			ft_putchar_fd(char c, int fd);
void			ft_bzero(void *s, size_t n);
int				ft_atoi_down(const char *str, int *index);
int				ft_mstout(const char *format, int i, int *actual);
char			*ft_fill(char *result, int i, int k, int n);
char			*ft_itoa(int n);
int				ft_strlen(const char *s);
void			ft_putstr_fd(char *s, int fd);
char			*ft_toupper(char *str);
char			*ft_dub(unsigned int n);
char			*ft_filldub(char *result, int i, unsigned int n);
int				ft_printf(const char *format, ...);
int				ft_printfsecondpart(t_list *set, va_list *ap,
const char *format, int *i);
int				ft_predeterminer(const char *format, int *j,
t_list *set, va_list *ap);
int				ft_secpart(const char *format, int *j,
t_list *set, va_list *ap);
int				ft_seccpart(const char *format, int *j,
t_list *set, va_list *ap);
int				ft_therpart(const char *format, int *j, t_list *set);
int				ft_forthpart(const char *format, int *j, t_list *set);
int				ft_fifthpart(const char *format, int *j, t_list *set);
int				ft_process(t_list *set, va_list *ap);
char			*ft_converter(unsigned long int dec);
char			*ft_pstr(int *length, int unsigned long answer,
t_list *set, int *modfp);
int				ft_xupproc(t_list *set, int itera, int *iterw, int modfp);
int				ft_uxpout(t_list *set, va_list *ap, int modfp);
void			ft_cproc(t_list *set, int *iterw);
int				ft_cout(t_list *set, va_list *ap);
void			ft_diproc2(t_list *set, int *iterw);
int				ft_tes1(t_list *set, int *length, char *str, int answer);
int				ft_diout(t_list *set, va_list *ap);
int				ft_sproc(t_list *set, int *count, int *length, char **str);
int				ft_sout(t_list *set, va_list *ap);

#endif
