/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chhoflac <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:31:01 by chhoflac          #+#    #+#             */
/*   Updated: 2023/12/14 10:26:46 by chhoflac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		ft_printf(const char *s, ...);
int		ft_char(char c);
int		ft_decimal(int n);
int		ft_hexa_up(unsigned int n);
int		ft_hexa_low(unsigned int n);
int		ft_pointer(unsigned long long add);
void	ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_string(char *s);
int		ft_unsigned(unsigned int n);
int		ft_strlen(char *s);
int		ft_getsize(int n);

#endif
