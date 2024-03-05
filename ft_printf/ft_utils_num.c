/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:50:10 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:53:38 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size(int nb, int base)
{
	int	caratteri;

	caratteri = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		caratteri = ft_size(-nb, base) + 1;
	}
	while (nb > 0)
	{
		nb = nb / base;
		caratteri++;
	}
	return (caratteri);
}

void	ft_printnb(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = - (nb);
	}
	if (nb >= 10)
	{
		ft_printnb(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return ;
}

int	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_printnb(nb);
		return (11);
	}
	ft_printnb(nb);
	return (ft_size(nb, 10));
}
