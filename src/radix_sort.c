/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:21:46 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/18 04:17:07 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

static void	split_stacks(t_dblist **stack_a, t_dblist **stack_b,
					int index, size_t list_len)
{
	size_t	i;
	size_t	stack_a_size;

	i = 0;
	stack_a_size = ft_dblstsize(*stack_a);
	while (i++ < stack_a_size && !(is_sorted(*stack_a)
			&& is_reversed(*stack_b)))
	{
		if ((*(int *)(*stack_a)->content >> index) & 1)
		{
			if (ft_dblstsize(*stack_a) > 1)
				rotate(stack_a, 'a');
		}
		else if (i < list_len)
		{
			push_b(stack_a, stack_b);
		}
	}
	if (is_sorted(*stack_a) && is_reversed(*stack_b))
		while (*stack_b)
			push_a(stack_a, stack_b);
}

static void	refill_a(t_dblist **stack_a, t_dblist **stack_b, int index)
{
	int	first_elt;
	int	is_rotated;

	first_elt = 0;
	is_rotated = 0;
	while (*stack_b && !is_rotated)
	{
		if (!((*(int *)(*stack_b)->content >> index) & 1) &&
		!is_sorted(*stack_a))
		{
			if (!first_elt && ft_dblstsize(*stack_b) > 1)
			{
				first_elt = *(int *)(*stack_b)->content;
				if (ft_dblstsize(*stack_b) > 1)
					rotate(stack_b, 'b');
			}
			else if (*(int *)(*stack_b)->content != first_elt
			&& ft_dblstsize(*stack_b) > 1)
				rotate(stack_b, 'b');
			else
				is_rotated = 1;
		}
		else
			push_a(stack_a, stack_b);
	}
}

int	is_sorted(t_dblist *stack)
{
	while (stack)
	{
		if (stack->next)
			if (*(int *)stack->content > *(int *)stack->next->content)
				return (0);
		stack = stack->next;
	}
	return (1);
}

int	is_reversed(t_dblist *stack)
{
	while (stack)
	{
		if (stack->next)
			if (*(int *)stack->content < *(int *)stack->next->content)
				return (0);
		stack = stack->next;
	}
	return (1);
}

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
		refill_a(&stack_a, &stack_b, index);
	}
	ft_dblstclear(&stack_a, free);
	ft_dblstclear(&stack_b, free);
}
