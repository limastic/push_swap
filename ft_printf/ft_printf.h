/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfaust <nfaust@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 20:50:43 by nfaust            #+#    #+#             */
/*   Updated: 2024/01/26 15:40:20 by nfaust           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

size_t	ft_put_u(unsigned int nbr, int check);
int		ft_putnbr(long nbr, int check);
int		ft_putchar(char c);
int		ft_formats(char c, va_list arg);
int		ft_print_str(char *str);
int		ft_puthex(unsigned int nbr, char *base, int check);
int		ft_putptr(unsigned int nbr, char *base, int check);
int		ft_printf(const char *str, ...);

#endif
