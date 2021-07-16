#include "./../heade.h"

int	ft_seccpart(const char *format, int *j, t_list *set, va_list *ap)
{
	if (format[*j] == '-')
		set->fm = 1;
	else if (format[*j] == '0')
		set->fn = 1;
	else if (format[*j] > 48 && format[*j] < 58 && set->blocker == 0)
		set->fw = ft_atoi_down(format, j);
	else if (format[*j] == '*' && set->blocker == 0)
	{
		set->fw = va_arg(*ap, int);
		if (set->fw < 0)
		{
			set->fw *= -1;
			set->fm = 1;
		}
	}
	else
		return (0);
	return (1);
}

int	ft_secpart(const char *format, int *j, t_list *set, va_list *ap)
{
	int checker;

	checker = ft_seccpart(format, j, set, ap);
	if (format[*j] == '.' && (format[*j + 1] > 48 && format[*j + 1] < 58))
	{
		++(*j);
		if ((set->fa = ft_atoi_down(format, j)) < 0)
			set->fa = 0;
	}
	else if (format[*j] == '.' && format[*j + 1] == '*')
	{
		if ((set->fa = va_arg(*ap, int)) < 0)
			set->fa = 0;
		else if (set->fa == 0)
			set->faa = 1;
		++(*j);
	}
	else
		return (checker);
	return (++checker);
}

int	ft_therpart(const char *format, int *j, t_list *set)
{
	if (format[*j] == '.')
	{
		if (format[*j + 1] == '0')
			++(*j);
		set->fa = 0;
		set->faa = 1;
		set->blocker = 1;
	}
	else if (set->blocker == 1 && format[*j] > 48 && format[*j] < 58)
	{
		set->fa = ft_atoi_down(format, j);
		set->faa = 0;
		set->blocker = 0;
	}
	else if (format[*j] == 'c')
	{
		set->sc = 1;
		return (2);
	}
	else
		return (0);
	return (1);
}

int	ft_forthpart(const char *format, int *j, t_list *set)
{
	if (format[*j] == 's')
	{
		set->ss = 1;
		return (2);
	}
	else if (format[*j] == 'p')
	{
		set->sp = 1;
		return (2);
	}
	else if (format[*j] == 'd')
	{
		set->sd = 1;
		return (2);
	}
	else if (format[*j] == 'i')
	{
		set->si = 1;
		return (2);
	}
	else
		return (0);
	return (1);
}

int	ft_fifthpart(const char *format, int *j, t_list *set)
{
	if (format[*j] == 'u')
	{
		set->su = 1;
		return (2);
	}
	else if (format[*j] == 'x')
	{
		set->sx = 1;
		return (2);
	}
	else if (format[*j] == 'X')
	{
		set->sbs = 1;
		return (2);
	}
	else
		return (0);
	return (1);
}
