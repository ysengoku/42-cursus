#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	i;

	count = 0;
	i = lst;
	while (i)
	{
		i = i->next;
		count++;
	}
	return (count);
}