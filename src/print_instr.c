/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 06:07:54 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/16 02:06:33 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap.h"

void	print_instr(t_dblist *stack_a, int argc)
{
	if (argc > 10)
		radix_sort(stack_a, argc);
	//else
	//	selection_sort(stack_a);
}
