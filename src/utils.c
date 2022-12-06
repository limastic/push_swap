/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:26:12 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/06 16:19:25 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
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

t_list	*create_list(char **argv)
{
	size_t	i;
	char	**numbers;
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	i = 0;
	while (argv[i])
	{
		numbers = ft_split(argv[i], ' ');
		while (numbers[i])
			
	}
}
