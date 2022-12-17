/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:07:54 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/17 07:57:59 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_instr(t_dblist *stack_a)
{
	size_t	list_len;

	list_len = ft_dblstsize(stack_a);
	if (list_len <= 3)
		little_sort(stack_a, list_len);
	if (list_len > 3)
		radix_sort(stack_a, list_len);
}
