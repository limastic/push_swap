/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 02:42:12 by nfaust            #+#    #+#             */
/*   Updated: 2022/11/18 02:52:54 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*lst_temp;

	lst_temp = lst;
	i = 0;
	while (lst_temp)
	{
		i++;
		lst_temp = lst_temp->next;
	}
	return (i);
}
