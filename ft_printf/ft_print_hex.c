/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 13:02:08 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/14 18:22:36 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_upper(unsigned long n)
{
	int			i;
	const char	*base;

	base = "0123456789ABCDEF";
	i = 0;
	if (n >= 16)
	{
		i += ft_hex_upper(n / 16);
		i += ft_hex_upper(n % 16);
	}
	else
		i += ft_charprint(base[n]);
	return (i);
}

int	ft_putnbr_hex(unsigned long n)
{
	int			i;
	const char	*base;

	base = "0123456789abcdef";
	i = 0;
	if (n >= 16)
	{
		i += ft_putnbr_hex(n / 16);
		i += ft_putnbr_hex (n % 16);
	}
	else
		i += ft_charprint(base[n]);
	return (i);
}

int	ft_pointer(unsigned long n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_printstr("(nil)");
	else
	{
		i += ft_printstr("0x");
		i += ft_putnbr_hex(n);
	}
	return (i);
}
