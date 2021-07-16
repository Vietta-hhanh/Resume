#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*new;
	t_list	*root;

	if (lst == 0 || f == 0)
		return (0);
	if (!(new = ft_lstnew(f(lst->content))))
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	root = new;
	new = new->next;
	lst = lst->next;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&lst, del);
			ft_lstclear(&root, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&root, new);
	}
	return (root);
}
