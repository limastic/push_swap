/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:44:05 by nfaust            #+#    #+#             */
/*   Updated: 2022/12/18 04:02:18 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"

int			error_management(char **argv);
int			check_duplicate(t_dblist *list);
int			is_sorted(t_dblist *stack);
int			is_reversed(t_dblist *stack);
void		free_arr(char **arr);
void		print_instr(t_dblist *stack_a);
void		push_b(t_dblist **stack_a, t_dblist **stack_b);
void		push_a(t_dblist **stack_a, t_dblist **stack_b);
void		rotate(t_dblist **stack, char stack_id);
void		rrotate(t_dblist **stack, char stack_id);
void		swap(t_dblist **stack, char stack_id);
void		radix_sort(t_dblist *stack_a, size_t list_len);
void		little_sort(t_dblist *stack_a, size_t list_len);
void		selection_sort(t_dblist *stack_a);
char		**skip_zeros(char **numbers);
t_dblist	*create_list(char **argv);
t_dblist	*map_atoi(t_dblist *list);

void		print_dblst(t_dblist *list);

#endif
