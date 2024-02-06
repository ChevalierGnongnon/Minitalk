/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:08:57 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/06 09:49:12 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "printf/ft_printf.h"

/*
 * Pour chaque signal decaller les bits
 */

void	ft_append(char c, char *s, int *call)
{
	if (!s)
		return ;
	if (c == '\0')
	{
		write(1, s, ft_strlen(s));
		free(s);
		*call = 0;
	}
	else
	{
		while (*s)
			s++;
		*s = c;
	}
}

char	*ft_malloc(unsigned long long size)
{
	char				*s;
	unsigned long long	i;

	i = 0;
	s = malloc(size);
	if (!s)
		return (NULL);
	while (i < size)
		s[i++] = '\0';
	return (s);
}

void	get_signal(int signal)
{
	static int					i;
	static char					bin;
	static unsigned long long	size = 0;
	static int					call;
	static char					*str;

	if (call < 64 && signal == SIGUSR1)
		size |= 0 << call++;
	else if (call < 64 && signal == SIGUSR2)
		size |= 1 << call++;
	else if (signal == SIGUSR1)
		bin |= 0 << i++;
	else if (signal == SIGUSR2)
		bin |= 1 << i++;
	if (call == 64 && call++)
		str = ft_malloc(size + 1);
	if (i == 8)
	{
		i = 0;
		ft_append(bin, str, &call);
		if (bin == '\0')
			size = 0;
		bin = 0;
	}
}

int	main(void)
{
	signal(SIGUSR1, get_signal);
	signal(SIGUSR2, get_signal);
	ft_printf("%d", getpid());
	while (1)
		;
	return (0);
}
