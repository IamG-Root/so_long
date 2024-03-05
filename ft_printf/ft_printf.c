/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:35:16 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:49:53 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	caratteristampati;
	int	i;

	caratteristampati = 0;
	i = 0;
	if (!s)
	{
		write (1, "(null)", 6);
		return (6);
	}
	while (s[i])
	{
		caratteristampati = caratteristampati + ft_putchar(s[i]);
		i++;
	}
	return (caratteristampati);
}

int	ft_stampaquesto(va_list lista, const char type)
{
	int	caratteristampati;

	caratteristampati = 0;
	if (type == 'c')
		caratteristampati = ft_putchar(va_arg(lista, int));
	else if (type == 's')
		caratteristampati = ft_putstr(va_arg(lista, char *));
	else if (type == 'p')
		caratteristampati = ft_putptr(va_arg(lista, unsigned long long));
	else if (type == 'd')
		caratteristampati = ft_putnbr(va_arg(lista, int));
	else if (type == 'i')
		caratteristampati = ft_putnbr(va_arg(lista, int));
	else if (type == 'u')
		caratteristampati = ft_putuint(va_arg(lista, unsigned int));
	else if (type == 'x' || type == 'X')
		caratteristampati = ft_putnbrhex(va_arg(lista, unsigned int), type);
	else if (type == '%')
		caratteristampati = ft_putchar('%');
	else
	{
		caratteristampati = caratteristampati + ft_putchar('%');
		caratteristampati = caratteristampati + ft_putchar(type);
	}
	return (caratteristampati);
}

int	ft_printf(const char *formato, ...)
{
	int		k;
	int		printed;
	va_list	lista;

	k = 0;
	printed = 0;
	va_start(lista, formato);
	while (formato[k])
	{
		if (formato[k] == '%')
		{
			printed = printed + ft_stampaquesto(lista, formato[k + 1]);
			k++;
		}
		else
			printed = printed + ft_putchar(formato[k]);
		k++;
	}
	return (printed);
}
