/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:23:32 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/14 18:22:18 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_format(char c, va_list args);
int	ft_printstr(char *str);
int	ft_charprint(char c);
int	ft_hex_upper(unsigned long n);
int	ft_putnbr_hex(unsigned long n);
int	ft_pointer(unsigned long n);
int	ft_printd(long int n);
int	ft_printu(int n);

#endif
