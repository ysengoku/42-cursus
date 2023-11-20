/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:13:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/20 09:08:39 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*node;

	if (!lst || !f || !del)
		return (NULL);
	newlst = NULL;
	while (lst)
	{
		node = ft_lstnew(f(lst->content));
		if (!node)
		{
			ft_lstclear(&newlst, del);
			return (NULL);
		}
		ft_lstadd_back(&newlst, node);
		lst = lst->next;
	}
	return (newlst);
}

/*int	main()
{
	t_list	list;
	t_list	node1;
	t_list	node2;
	t_list	node3;
	char	*s1 = ft_strdup("abc");
	char	*s2 = ft_strdup("cdef");
	char	*s3 = ft_strdup("ghijk");
	
	node1 = ft_lstnew(s1);
	node2 = ft_lstnew(s2);
	node3 = ft_lstnew(s3);
	node1->next = node2;
	node2->next = node3;
	node3->next = NULL;
	list = *node1;

	while(list)
	{
		
	}
	ft_lstmap()
}*/
