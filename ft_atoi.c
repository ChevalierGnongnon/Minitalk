/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 10:23:04 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/05 10:31:16 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_pass_empty(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

static int	ft_transform(const char *nptr, int key)
{
	int	nb;

	nb = 0;
	while (nptr[key] >= '0' && nptr[key] <= '9')
	{
		nb = nb * 10 + (nptr[key] - '0');
		key++;
	}
	return (nb);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	cnt;
	int	nb;
	int	mult;

	mult = 1;
	cnt = 0;
	i = ft_pass_empty(nptr);
	while (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			mult = -1;
		i++;
		cnt++;
	}
	if (cnt > 1)
		return (0);
	nb = ft_transform(nptr, i);
	return (nb * mult);
}
