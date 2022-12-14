/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:12 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/14 23:23:37 by nfaust           ###   ########.fr       */
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

	numbers = skip_zeros(ft_split(argv[0], ' '));
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
		numbers = skip_zeros(ft_split(argv[i++], ' '));
		if (!numbers)
			return (NULL);
		j = 0;
		while (numbers[j])
			ft_dblstadd_back(&list, ft_dblstnew(ft_strdup(numbers[j++])));
		free_arr(numbers);
	}
	return (list);
}

char	**skip_zeros(char **numbers)
{
	ssize_t	i;
	size_t	j;
	size_t	k;

	if (!numbers)
		return (NULL);
	i = -1;
	while (numbers[++i])
	{
		j = 0;
		k = 0;
		if (numbers[i][j] == '-' && ++k)
			j++;
		while (numbers[i][j] == '0' && numbers[i][j + 1])
			j++;
		if (j)
		{
			if (k)
				numbers[i][k - 1] = '-';
			while (numbers[i][j])
				numbers[i][k++] = numbers[i][j++];
			numbers[i][k] = 0;
		}
	}
	return (numbers);
}
