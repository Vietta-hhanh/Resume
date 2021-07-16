#include "./../heade.h"

int		ft_tes1(t_list *set, int *length, char *str, int answer)
{
	int itera;
	int iterw;

	itera = 0;
	iterw = 0;
	*length = ft_strlen(str);
	if (set->faa == 1 && set->fa == 0 && answer == 0)
		*length = 0;
	if (set->fa > *length - set->freeflag)
		itera = set->fa - *length + set->freeflag;
	if ((iterw = set->fw - *length - itera) < 0)
		iterw = 0;
	set->count = *length + iterw + itera;
	if (set->fn == 0 && set->fm == 0 && iterw > 0)
		while (iterw-- > 0)
			ft_putchar_fd(' ', 1);
	if (set->freeflag == 1)
		ft_putchar_fd('-', 1);
	if (itera > 0)
		while (itera-- > 0)
			ft_putchar_fd('0', 1);
	if (set->fm == 0 && iterw > 0)
		while (iterw-- > 0)
			ft_putchar_fd('0', 1);
	return (iterw);
}

void	ft_diproc2(t_list *set, int *iterw)
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
}

int		ft_diout(t_list *set, va_list *ap)
{
	int		answer;
	char	*str;
	int		length;
	int		iterw;

	answer = va_arg(*ap, int);
	if (answer < 0)
		set->freeflag = 1;
	if ((str = ft_itoa(answer)) == 0)
		return (-1);
	length = 0;
	iterw = ft_tes1(set, &length, str, answer);
	if (set->freeflag == 1)
		++str;
	if (length != 0)
		ft_putstr_fd(str, 1);
	ft_diproc2(set, &iterw);
	if (set->freeflag == 1)
		--str;
	free(str);
	return (set->count);
}

int		ft_sproc(t_list *set, int *count, int *length, char **str)
{
	int iterw;

	if (*str == 0)
	{
		*str = "(null)";
		set->freeflag = 1;
	}
	*length = ft_strlen(*str);
	if (set->freeflag == 1 && set->fa < 6 && set->fa != 0)
		*length = 0;
	else if (set->fa < *length && set->faa == 0 && set->fa != 0)
		*length = set->fa;
	else if (set->faa == 1)
		*length = 0;
	if ((iterw = set->fw - *length) < 0)
		iterw = 0;
	*count = *length + iterw;
	if (set->fn == 0 && set->fm == 0 && iterw > 0)
		while (iterw-- > 0)
			ft_putchar_fd(' ', 1);
	if (set->fm == 0 && iterw > 0)
		while (iterw-- > 0)
			ft_putchar_fd(' ', 1);
	return (iterw);
}

int		ft_sout(t_list *set, va_list *ap)
{
	char	*str;
	int		length;
	int		iterw;
	int		count;
	int		i;

	i = 0;
	count = 0;
	length = 0;
	str = va_arg(*ap, char *);
	iterw = ft_sproc(set, &count, &length, &str);
	while (i < length)
		ft_putchar_fd(str[i++], 1);
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
