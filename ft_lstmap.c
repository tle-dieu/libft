#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *fcpy;

	if (lst)
	{
		fcpy = f(lst);
		if (fcpy && lst->next)
			fcpy->next = ft_lstmap(lst->next, f);
		return (fcpy);
	}
	return (NULL);
}
