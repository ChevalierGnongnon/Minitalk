/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 16:32:43 by chhoflac          #+#    #+#             */
/*   Updated: 2023/12/05 13:36:33 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_fd(int n, int fd)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{	
		ft_putstr_fd("-2147483648", fd);
		i = 11;
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n *= -1;
			i++;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
			i++;
		}
		ft_putchar_fd((n % 10) + '0', fd);
		i++;
	}
	return (i);
}
