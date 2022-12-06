/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 03:48:10 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/22 19:50:09 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*first_elt;

	if (!lst || !f || !del)
		return (NULL);
	first_elt = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (!new)
		{
			while (first_elt)
			{
				new = first_elt->next;
				del(first_elt->content);
				free(first_elt);
				first_elt = new;
			}
			return (NULL);
		}
		ft_lstadd_back(&first_elt, new);
		lst = lst->next;
	}
	return (first_elt);
}
