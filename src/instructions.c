/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:04:31 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/15 23:11:51 by nfaust           ###   ########.fr       */
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
		(*stack_a)->prev = NULL;
	}
	else
		*stack_a = NULL;
	ft_printf("pb\n");
}

void	push_a(t_dblist **stack_a, t_dblist **stack_b)
{
	ft_dblstadd_front(stack_a, ft_dblstnew((*stack_b)->content));
	if ((*stack_b)->next)
	{
		*stack_b = (*stack_b)->next;
		(*stack_b)->prev = NULL;
	}
	else
		*stack_b = NULL;
	ft_printf("pa\n");
}

void	rotate_a(t_dblist **stack_a)
{
	t_dblist	*save;

	save = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = NULL;
	while ((*stack_a)->next)
		*stack_a = (*stack_a)->next;
	(*stack_a)->next = save;
	(*stack_a)->next->prev = *stack_a;
	(*stack_a)->next->next = NULL;
	while ((*stack_a)->prev)
		*stack_a = (*stack_a)->prev;
	ft_printf("ra\n");
}

void	rotate_b(t_dblist **stack_b)
{
	t_dblist	*save;

	save = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = NULL;
	while ((*stack_b)->next)
		*stack_b = (*stack_b)->next;
	(*stack_b)->next = save;
	(*stack_b)->next->prev = *stack_b;
	(*stack_b)->next->next = NULL;
	while ((*stack_b)->prev)
		*stack_b = (*stack_b)->prev;
	ft_printf("ra\n");
}
