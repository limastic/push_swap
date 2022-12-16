/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:21:46 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/16 02:50:06 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	split_stacks(t_dblist **stack_a, t_dblist **stack_b,
					int index, int argc)
{
	int	i;

	i = 0;
	while (i++ < argc - 1)
	{
		if ((*(int *)(*stack_a)->content >> index) & 1)
			rotate_a(stack_a);
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

void	radix_sort(t_dblist *stack_a, int argc)
{
	t_dblist	*stack_b;
	int			i;
	int			index;

	i = 32;
	index = 0;
	stack_b = NULL;
	while (index < i && !is_sorted(stack_a))
	{
		split_stacks(&stack_a, &stack_b, index++, argc);
		refill_a(&stack_a, &stack_b);
	}
	ft_dblstclear(&stack_a, free);
	ft_dblstclear(&stack_b, free);
}
