/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:12 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/12 22:39:41 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	free_arr(char **arr)
{
	size_t	i;

	i = 0;
	if (arr)
	{
		while (arr[i])
			free(arr[i++]);
		free(arr);
	}
}

t_dblist	*create_list(char **argv)
{
	size_t		i;
	size_t		j;
	char		**numbers;
	t_dblist	*list;

	numbers = ft_split(argv[0], ' ');
	if (!numbers)
		return (NULL);
	list = ft_dblstnew(ft_strdup(numbers[0]));
	j = 1;
	while (numbers[j])
		ft_dblstadd_back(&list, ft_dblstnew(ft_strdup(numbers[j++])));
	i = 1;
	free_arr(numbers);
	while (argv[i])
	{
		numbers = ft_split(argv[i++], ' ');
		if (!numbers)
			return (NULL);
		j = 0;
		while (numbers[j])
			ft_dblstadd_back(&list, ft_dblstnew(ft_strdup(numbers[j++])));
		free_arr(numbers);
	}
	return (list);
}

void	*free_dblst(t_dblist *list)
{
	t_dblist	*temp;

	while (list->next)
	{
		temp = list;
		list = list->next;
		free(temp);
	}
	free(list);
}
