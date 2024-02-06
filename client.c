/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 19:53:44 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/06 09:40:01 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, __pid_t pid)
{
	short	i;

	i = 0;
	while (i++ < 8)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		usleep(100);
	}
}

void	send_size(unsigned long long c, __pid_t pid)
{
	short	i;

	i = 0;
	while (i++ < 64)
	{
		if (c & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c >>= 1;
		usleep(100);
	}
}

void	send_string(char *s, __pid_t pid)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		send_char(s[i], pid);
		i++;
	}
	send_char('\0', pid);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
	{
		send_size(ft_strlen(argv[2]), ft_atoi(argv[1]));
		send_string(argv[2], ft_atoi(argv[1]));
	}
}
