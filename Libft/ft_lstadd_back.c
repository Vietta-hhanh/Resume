#include "libft.h"

void		ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*p;

	if (!(new))
		return ;
	p = *lst;
	if (!p)
	{
		*lst = new;
		return ;
	}
	while (p->next)
		p = p->next;
	p->next = new;
}
