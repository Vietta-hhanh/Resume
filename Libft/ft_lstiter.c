#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (f == 0 || lst == 0)
		return ;
	while (lst->next)
	{
		f(lst->content);
		lst = lst->next;
	}
	f(lst->content);
}
