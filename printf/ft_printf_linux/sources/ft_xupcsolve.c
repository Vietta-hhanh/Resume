#include "./../heade.h"

char	*ft_pstr(int *length, int unsigned long answer, t_list *set, int *modfp)
{
	char *str;

	if (set->su == 1)
		str = ft_dub(answer);
	else if (answer == 0 && set->sp == 1)
	{
		set->freeflag = 0;
		str = "(nil)";
		*modfp = 0;
	}
	else
		str = ft_converter(answer);
	if (str == 0)
		return (0);
	if (set->sbs == 1)
		str = ft_toupper(str);
	*length = ft_strlen(str);
	if (answer == 0 && set->sp == 1)
		set->fa = 0;
	else if (set->faa == 1 && set->fa == 0 && answer == 0)
		*length = 0;
	return (str);
}

int		ft_xupproc(t_list *set, int itera, int *iterw, int modfp)
{
	if (itera == -1)
	{
		if (*iterw > 0)
		{
			if (set->fn == 0)
				while ((*iterw)-- > 0)
					ft_putchar_fd(' ', 1);
			else
				while ((*iterw)-- > 0)
					ft_putchar_fd('0', 1);
		}
		return (0);
	}
	if (set->fn == 0 && set->fm == 0 && *iterw > 0)
		while ((*iterw)-- > 0)
			ft_putchar_fd(' ', 1);
	if (set->sp && modfp != 0)
		ft_putstr_fd("0x", 1);
	if (itera > 0)
		while (itera-- > 0)
			ft_putchar_fd('0', 1);
	if (set->fm == 0 && *iterw > 0)
		while ((*iterw)-- > 0)
			ft_putchar_fd('0', 1);
	return (itera);
}

int		ft_uxpout(t_list *set, va_list *ap, int modfp)
{
	int unsigned long	answer;
	char				*str;
	int					length;
	int					itera;
	int					iterw;

	set->freeflag = 1;
	answer = va_arg(*ap, unsigned long int);
	length = 0;
	if ((str = ft_pstr(&length, answer, set, &modfp)) == 0)
		return (-1);
	itera = 0;
	if (set->fa > length)
		itera = set->fa - length;
	if ((iterw = set->fw - length - itera - modfp) < 0)
		iterw = 0;
	set->count = length + iterw + itera + modfp;
	itera = ft_xupproc(set, itera, &iterw, modfp);
	if (length != 0)
		ft_putstr_fd(str, 1);
	itera = ft_xupproc(set, -1, &iterw, modfp);
	if (set->freeflag == 1)
		free(str);
	return (set->count);
}

void	ft_cproc(t_list *set, int *iterw)
{
	if (set->fn == 0 && set->fm == 0 && *iterw > 0)
		while ((*iterw)-- > 0)
			ft_putchar_fd(' ', 1);
	if (set->fm == 0 && *iterw > 0)
		while ((*iterw)-- > 0)
			ft_putchar_fd(' ', 1);
}

int		ft_cout(t_list *set, va_list *ap)
{
	int answer;
	int length;
	int iterw;
	int count;

	count = 0;
	answer = va_arg(*ap, int);
	length = 1;
	if ((iterw = set->fw - length) < 0)
		iterw = 0;
	count = length + iterw;
	ft_cproc(set, &iterw);
	ft_putchar_fd(answer, 1);
	if (iterw > 0)
	{
		if (set->fn == 0)
			while (iterw-- > 0)
				ft_putchar_fd(' ', 1);
		else
			while (iterw-- > 0)
				ft_putchar_fd(' ', 1);
	}
	return (count);
}
