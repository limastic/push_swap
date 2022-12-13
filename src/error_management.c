/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:39:31 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/13 20:34:07 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#define MAX_INT "2147483647"

static int	check_non_numeric(char **argv)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (1);
			if (argv[i][j] == '-' && j && argv[i][j - 1] == '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	check_overflow(char *number)
{
	size_t	i;
	size_t	k;
	int		is_neg;

	i = 0;
	k = 0;
	is_neg = 0;
	if (number[i] == '-')
	{
		is_neg = 1;
		i++;
	}
	while (number[i])
	{
		if (number[i] > MAX_INT[k])
		{
			if (is_neg && k == 9 && number[i] == (MAX_INT[k] + 1))
				return (0);
			return (1);
		}
		if (number[i++] < MAX_INT[k++])
			return (0);
	}
	return (0);
}

static int	check_len(char **argv)
{
	size_t	i;
	size_t	j;
	size_t	max_len;
	char	**numbers;

	i = 0;
	while (argv[i])
	{
		j = 0;
		numbers = ft_split(argv[i], ' ');
		while (numbers[j])
		{	
			max_len = 10;
			if (numbers[j][0] == '-')
				max_len++;
			if (ft_strlen(numbers[j]) > max_len)
				return (free_arr(numbers), 1);
			if (ft_strlen(numbers[j]) == max_len && check_overflow(numbers[j]))
				return (free_arr(numbers), 1);
			j++;
		}
		free_arr(numbers);
		i++;
	}
	return (0);
}

int	error_management(char **argv)
{
	if (!argv[0])
		return (1);
	if (check_non_numeric(argv) || check_len(argv))
		return (-1);
	return (0);
}

int	check_duplicate(t_dblist *list)
{
	t_dblist	*tmp;
	size_t		tmp_len;

	if (list)
	{
		while (list->next)
		{
			tmp = list;
			tmp_len = ft_strlen(tmp->content);
			while (list->next)
			{
				list = list->next;
				if (!ft_memcmp(tmp->content, list->content, tmp_len + 1))
					return (1);
			}
			list = tmp->next;
		}
	}
	return (0);
}
