/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:04:31 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/16 02:48:56 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include "../ft_printf/ft_printf.h"

void	push_b(t_dblist **stack_a, t_dblist **stack_b)
{
	ft_dblstadd_front(stack_b, ft_dblstnew((*stack_a)->content));
	if ((*stack_a)->next)
	{
		*stack_a = (*stack_a)->next;
		free((*stack_a)->prev);
		(*stack_a)->prev = NULL;
	}
	else
	{
		free(*stack_a);
		*stack_a = NULL;
	}
	ft_printf("pb\n");
}

void	push_a(t_dblist **stack_a, t_dblist **stack_b)
{
	ft_dblstadd_front(stack_a, ft_dblstnew((*stack_b)->content));
	if ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		free((*stack_b)->prev);
		(*stack_b)->prev = NULL;
	}
	else
	{
		free(*stack_b);
		*stack_b = NULL;
	}
	ft_printf("pa\n");
}

void	rotate_a(t_dblist **stack_a)
{
	int	*value;

	value = malloc(sizeof(int));
	*value = *(int *)(*stack_a)->content;
	*stack_a = (*stack_a)->next;
	ft_dblstdelone((*stack_a)->prev, free);
	(*stack_a)->prev = NULL;
	ft_dblstadd_back(stack_a, ft_dblstnew(value));
	ft_printf("ra\n");
}

void	rotate_b(t_dblist **stack_b)
{
	int	*value;

	value = malloc(sizeof(int));
	*value = *(int *)(*stack_b)->content;
	*stack_b = (*stack_b)->next;
	ft_dblstdelone((*stack_b)->prev, free);
	(*stack_b)->prev = NULL;
	ft_dblstadd_back(stack_b, ft_dblstnew(value));
	ft_printf("rb\n");
}
