/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:56:34 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:58:21 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_size_uint(unsigned int nb, int base)
{
	int	caratteri;

	caratteri = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / base;
		caratteri++;
	}
	return (caratteri);
}

void	ft_printnb_uint(unsigned int nb)
{
	if (nb >= 10)
	{
		ft_printnb_uint(nb / 10);
		nb = nb % 10;
	}
	if (nb < 10)
		ft_putchar(nb + 48);
	return ;
}

int	ft_putuint(unsigned int nb)
{
	ft_printnb_uint(nb);
	return (ft_size_uint(nb, 10));
}
