/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:44:05 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/15 06:17:43 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

int			error_management(char **argv);
int			check_duplicate(t_dblist *list);
void		free_arr(char **arr);
void		print_instr(t_dblist *stack_a, int argc);
char		**skip_zeros(char **numbers);
t_dblist	*create_list(char **argv);
t_dblist	*map_atoi(t_dblist *list);

#endif
