/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scastagn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 08:53:55 by scastagn          #+#    #+#             */
/*   Updated: 2023/02/06 08:56:20 by scastagn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptrsize(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (1);
	while (ptr != 0)
	{
		ptr = ptr / 16;
		size++;
	}
	return (size + 2);
}

void	ft_print_ptr(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_print_ptr(ptr / 16);
		ft_print_ptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
	return ;
}

int	ft_putptr(unsigned long long ptr)
{
	write(1, "0x", 2);
	if (ptr == 0)
		return (write(1, "0", 1) + 2);
	ft_print_ptr(ptr);
	return (ft_ptrsize(ptr));
}
