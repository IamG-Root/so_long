/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:46:11 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:48:48 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexlenght(unsigned int nb)
{
	int	lenght;

	lenght = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		lenght++;
		nb = nb / 16;
	}
	return (lenght);
}

void	ft_printhex(unsigned int nb, const char type)
{
	if (nb >= 16)
	{
		ft_printhex(nb / 16, type);
		ft_printhex(nb % 16, type);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar(nb + '0');
		}
		else
		{
			if (type == 'x')
				ft_putchar(nb - 10 + 'a');
			else if (type == 'X')
				ft_putchar(nb - 10 + 'A');
		}
	}
	return ;
}

int	ft_putnbrhex(int nb, const char type)
{
	ft_printhex(nb, type);
	return (ft_hexlenght(nb));
}
