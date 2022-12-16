/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:07:54 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/16 04:44:10 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"
#include <stdio.h>

void	print_instr(t_dblist *stack_a)
{
	size_t	list_len;

	list_len = ft_dblstsize(stack_a);
	//if (list_len > 10)
	radix_sort(stack_a, list_len);
	//else
	//	selection_sort(stack_a);
}
