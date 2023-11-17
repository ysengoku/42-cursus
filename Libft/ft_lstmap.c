/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yusengok <yusengok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 12:13:50 by yusengok          #+#    #+#             */
/*   Updated: 2023/11/17 16:04:14 by yusengok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*tmp;

	if (!lst || !f || !des)
		return (NULL);
	tmp = lst;
	newlst = ft_lstnew(f(tmp->content));
	while (tmp)
	{
		newlst->next = ft_lstnew(f(tmp->content));
			if (!newlst)
				
		tmp = tmp->next;
	}
	return (newlst);
}
