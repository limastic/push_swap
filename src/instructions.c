/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:04:31 by nfaust            #+#    #+#             */
/*   Updated: 2023/01/05 23:35:32 by nfaust           ###   ########.fr       */
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

void	rotate(t_dblist **stack, char stack_id)
{
	int	*value;

	value = malloc(sizeof(int));
	if (!value)
		return ;
	*value = *(int *)(*stack)->content;
	*stack = (*stack)->next;
	ft_dblstdelone((*stack)->prev, free);
	(*stack)->prev = NULL;
	ft_dblstadd_back(stack, ft_dblstnew(value));
	ft_printf("r%c\n", stack_id);
}

void	rrotate(t_dblist **stack, char stack_id)
{
	int	*value;

	value = malloc(sizeof(int));
	if (!value)
		return ;
	*stack = ft_dblstlast(*stack);
	*value = *(int *)(*stack)->content;
	*stack = (*stack)->prev;
	ft_dblstdelone((*stack)->next, free);
	(*stack)->next = NULL;
	while ((*stack)->prev)
		*stack = (*stack)->prev;
	ft_dblstadd_front(stack, ft_dblstnew(value));
	ft_printf("rr%c\n", stack_id);
}

void	swap(t_dblist **stack, char stack_id)
{
	int	*temp;

	temp = (int *)(*stack)->content;
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = temp;
	ft_printf("s%c\n", stack_id);
}
