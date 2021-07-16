#include "libft.h"

t_list		*ft_lstnew(void *content)
{
	t_list	*d;

	if (!(d = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	d->content = content;
	d->next = NULL;
	return (d);
}
