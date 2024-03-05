/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:44:27 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:45:39 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_putchar(unsigned char c);
int		ft_putstr(const char *s);
int		ft_size(int nb, int base);
void	ft_printnb(int nb);
int		ft_putnbr(int nb);
int		ft_hexlenght(unsigned int nb);
void	ft_printhex(unsigned int nb, const char type);
int		ft_putnbrhex(int nb, const char type);
int		ft_size_uint(unsigned int nb, int base);
void	ft_printnb_uint(unsigned int nb);
int		ft_putuint(unsigned int nb);
int		ft_ptrsize(unsigned long long ptr);
void	ft_print_ptr(unsigned long long ptr);
int		ft_putptr(unsigned long long ptr);
int		ft_stampaquesto(va_list lista, const char type);
int		ft_printf(const char *formato, ...);
#endif
