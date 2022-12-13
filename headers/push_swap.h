/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:44:05 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/13 20:35:56 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

int			error_management(char **argv);
int			check_duplicate(t_dblist *list);
void		free_arr(char **arr);
t_dblist	*create_list(char **argv);

#endif
