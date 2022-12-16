/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:21:46 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/16 05:15:49 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	split_stacks(t_dblist **stack_a, t_dblist **stack_b,
					int index, size_t list_len)
{
	size_t	i;

	i = 0;
	while (i++ < list_len)
	{
		if ((*(int *)(*stack_a)->content >> index) & 1)
		{
			if (ft_dblstsize(*stack_a) > 1)
				rotate_a(stack_a);
		}
		else
			push_b(stack_a, stack_b);
	}
}

static void	refill_a(t_dblist **stack_a, t_dblist **stack_b)
{
	while (*stack_b)
	{
		push_a(stack_a, stack_b);
	}
}

static int	is_sorted(t_dblist *stack_a)
{
	while (stack_a)
	{
		if (stack_a->next)
			if (*(int *)stack_a->content > *(int *)stack_a->next->content)
				return (0);
		stack_a = stack_a->next;
	}
	return (1);
}

#include <stdio.h>

void	radix_sort(t_dblist *stack_a, size_t list_len)
{
	t_dblist	*stack_b;
	int			i;
	int			index;

	i = 32;
	index = 0;
	stack_b = NULL;
	while (index < i && !is_sorted(stack_a))
	{
		split_stacks(&stack_a, &stack_b, index++, list_len);
		refill_a(&stack_a, &stack_b);
	}
	ft_dblstclear(&stack_a, free);
	ft_dblstclear(&stack_b, free);
}
