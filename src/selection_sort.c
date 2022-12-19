/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:22:00 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/18 05:48:23 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static size_t	_get_min_ind(t_dblist *stack_a)
{
	size_t	min_ind;
	size_t	ind;
	int		min_value;

	ind = 0;
	min_ind = 0;
	min_value = *(int *)stack_a->content;
	stack_a = stack_a->next;
	while (stack_a)
	{
		ind++;
		if (*(int *)stack_a->content < min_value)
		{
			min_value = *(int *)stack_a->content;
			min_ind = ind;
		}
		stack_a = stack_a->next;
	}
	return (min_ind);
}

static int	_get_min_value(t_dblist *stack_a)
{
	int	min_value;

	min_value = *(int *)stack_a->content;
	while (stack_a)
	{
		if (*(int *)stack_a->content < min_value)
			min_value = *(int *)stack_a->content;
		stack_a = stack_a->next;
	}
	return (min_value);
}

static void	_push_min(t_dblist **stack_a, t_dblist **stack_b)
{
	size_t	list_len;
	size_t	min_ind;
	int		min_value;

	list_len = ft_dblstsize(*stack_a);
	min_ind = _get_min_ind(*stack_a);
	min_value = _get_min_value(*stack_a);
	if (min_ind > list_len / 2)
	{
		while (*(int *)(*stack_a)->content != min_value)
			rrotate(stack_a, 'a');
	}
	else
	{
		while (*(int *)(*stack_a)->content != min_value)
			rotate(stack_a, 'a');
	}
	push_b(stack_a, stack_b);
}

void	selection_sort(t_dblist *stack_a)
{
	t_dblist	*stack_b;

	stack_b = NULL;
	while (ft_dblstsize(stack_a) > 2 && !is_sorted(stack_a))
		_push_min(&stack_a, &stack_b);
	if (!is_sorted(stack_a))
		rotate(&stack_a, 'a');
	while (stack_b)
		push_a(&stack_a, &stack_b);
	ft_dblstclear(&stack_a, free);
	ft_dblstclear(&stack_b, free);
}
