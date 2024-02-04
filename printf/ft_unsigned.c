/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 13:14:48 by chhoflac          #+#    #+#             */
/*   Updated: 2023/12/11 10:33:50 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	if (n > 9)
		ft_putnbr_unsigned(n / 10);
	ft_putchar_fd((n % 10) + 48, 1);
}

int	ft_getusize(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 1)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	ft_unsigned(unsigned int n)
{
	if (n == 0)
	{
		ft_putnbr_unsigned(n);
		return (1);
	}
	ft_putnbr_unsigned(n);
	return (ft_getusize(n));
}
