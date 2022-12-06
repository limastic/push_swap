/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:15:52 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/06 16:15:22 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include "../headers/push_swap.h"

int	main(int argc, char **argv)
{
	int		error;
	t_list	list;

	error = error_management(argv + 1);
	if (error < 1)
	{
		if (error == -1)
			ft_printf("Error\n");
		return (0);
	}
	list = create_list(*argv + 1);
	return (0);
}
