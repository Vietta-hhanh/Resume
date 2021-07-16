#include "heade.h"

int	ft_predeterminer(const char *format, int *j, t_list *set, va_list *ap)
{
	int checker;

	checker = 1;
	while (1 == 1)
	{
		if (format[*j] == '%')
		{
			ft_putchar_fd('%', 1);
			return (1);
		}
		checker = ft_secpart(format, j, set, ap);
		if ((checker += ft_therpart(format, j, set)) == 2)
			return (0);
		if ((checker += ft_forthpart(format, j, set)) == 2)
			return (0);
		if ((checker += ft_fifthpart(format, j, set)) == 2)
			return (0);
		if (checker == 0)
			return (-1);
		++(*j);
	}
	return (-1);
}

int	ft_process(t_list *set, va_list *ap)
{
	int value;

	value = 0;
	if (set->fm == 1 || (set->fa && (set->sx == 1
	|| set->sbs == 1 || set->su == 1 || set->si == 1
	|| set->sd == 1)) || (set->faa == 1 && set->fa == 0
	&& (set->sd == 1 || set->si == 1 || set->su == 1
	|| set->sx == 1 || set->sbs == 1)))
		set->fn = 0;
	if (set->sc == 1)
		value = ft_cout(set, ap);
	else if (set->ss == 1)
		value = ft_sout(set, ap);
	else if (set->sp == 1)
		value = ft_uxpout(set, ap, 2);
	else if (set->sd == 1 || set->si == 1)
		value = ft_diout(set, ap);
	else if (set->sx == 1)
		value = ft_uxpout(set, ap, 0);
	else if (set->sbs == 1)
		value = ft_uxpout(set, ap, 0);
	else if (set->su == 1)
		value = ft_uxpout(set, ap, 0);
	return (value);
}

int	ft_printfsecondpart(t_list *set, va_list *ap, const char *format, int *i)
{
	int counter;
	int checker;

	checker = 0;
	counter = 0;
	if (format[*i] == '%')
	{
		++(*i);
		if ((checker = ft_predeterminer(format, i, set, ap)) < 0)
			return (-1);
		counter += checker;
		if ((checker = ft_process(set, ap)) < 0)
			return (-1);
		counter += checker;
	}
	else
	{
		ft_putchar_fd(format[*i], 1);
		++counter;
	}
	return (counter);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	int			counter;
	int			checker;
	int			i;
	t_list		set;

	counter = 0;
	checker = 0;
	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		ft_bzero(&set, sizeof(t_list));
		if ((checker = ft_printfsecondpart(&set, &ap, format, &i)) < 0)
		{
			va_end(ap);
			return (-1);
		}
		counter += checker;
		++i;
	}
	va_end(ap);
	return (counter);
}
