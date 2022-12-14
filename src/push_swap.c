/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:15:52 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/14 23:29:36 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	int			error;
	t_dblist	*list;

	(void) argc;
	error = error_management(argv + 1);
	if (error == -1)
		return (ft_printf("Error\n"), 0);
	if (error)
		return (0);
	list = create_list(argv + 1);
	if (check_duplicate(list))
		return (ft_dblstclear(&list, free), ft_printf("Error\n"), 0);
	while (list->next)
	{
		ft_printf("%s\n", list->content);
		list = list->next;
	}
	ft_printf("%s\n", list->content);
	while (list->prev)
		list = list->prev;
	ft_dblstclear(&list, free);
	return (0);
}
