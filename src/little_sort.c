/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   little_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 02:35:11 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/17 05:17:34 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	little_sort(t_dblist *stack_a, size_t list_len)
{
	if (is_sorted(stack_a))
		return (ft_dblstclear(&stack_a, free));
	if (list_len == 2)
		return (swap(&stack_a, 'a'));
	if (*(int *)stack_a->content == 0)
		return (swap(&stack_a, 'a'), rotate(&stack_a, 'a'),
			ft_dblstclear(&stack_a, free));
	else if (*(int *)stack_a->content == 1)
	{
		if (*(int *)stack_a->next->content == 0)
			swap(&stack_a, 'a');
		else
			rrotate(&stack_a, 'a');
	}
	else
	{
		if (*(int *)stack_a->next->content == 0)
			rotate(&stack_a, 'a');
		else
			return (swap(&stack_a, 'a'), rrotate(&stack_a, 'a'),
				ft_dblstclear(&stack_a, free));
	}
	ft_dblstclear(&stack_a, free);
}
