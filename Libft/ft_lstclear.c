#include "libft.h"

void		ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*new;
	t_list	*next;

	if (del == 0 || lst == 0)
		return ;
	next = *lst;
	while (next)
	{
		new = next;
		next = new->next;
		del(new->content);
		free(new);
	}
	*lst = NULL;
}
