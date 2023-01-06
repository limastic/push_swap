/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:15:52 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/06 00:08:19 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf/ft_printf.h"
#include "../headers/push_swap.h"

static t_dblist	*get_indexed_list(t_dblist *list)
{
	size_t		*count;
	t_dblist	*curr;
	t_dblist	*first_elt;
	t_dblist	*save_first;

	save_first = list;
	while (list)
	{
		count = malloc(sizeof(size_t));
		if (!count)
			return (ft_dblstclear(&list, free),
				ft_dblstclear(&first_elt, free), NULL);
		*count = 0;
		curr = save_first;
		while (curr)
		{
			if (*(int *)curr->content < *(int *)list->content)
				(*count)++;
			curr = curr->next;
		}
		list = list->next;
		ft_dblstadd_back(&first_elt, ft_dblstnew(count));
	}
	return (ft_dblstclear(&save_first, free), first_elt);
}

void	print_dblst(t_dblist *list)
{
	while (list)
	{
		ft_printf("%i ", *(int *)list->content);
		list = list->next;
	}
	ft_printf("\n");
}

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
	list = get_indexed_list(map_atoi(list));
	if (!list)
		return (ft_printf("Error\n"), 0);
	print_instr(list);
	return (0);
}
