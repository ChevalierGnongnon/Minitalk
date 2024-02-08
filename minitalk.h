/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <chhoflac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 22:40:46 by chhoflac          #+#    #+#             */
/*   Updated: 2024/02/08 09:58:42 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stddef.h>
# include <unistd.h>
# include "printf/ft_printf.h"
# include <stdlib.h>

int		ft_atoi(const char *nptr);
void	send_char(char c, __pid_t pid);
void	send_string(char *s, __pid_t pid);

#endif