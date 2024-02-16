/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:24:03 by nfaust            #+#    #+#             */
/*   Updated: 2024/01/26 15:34:14 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdint.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*alloc;

	if (size && count > SIZE_MAX / size)
		return (NULL);
	alloc = malloc(size * count);
	if (alloc == NULL)
		return (NULL);
	ft_bzero(alloc, size * count);
	return (alloc);
}
