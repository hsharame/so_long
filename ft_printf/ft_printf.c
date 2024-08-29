/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:59:05 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/12 11:51:09 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_charprint(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_printstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		ft_charprint(str[i]);
		i++;
	}
	return (i);
}

int	ft_format(char c, va_list args)
{
	int	i;

	i = 0;
	if (c == 'c')
		i += ft_charprint(va_arg(args, int));
	else if (c == '%')
		i += ft_charprint('%');
	else if (c == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (c == 'p')
		i += ft_pointer(va_arg(args, unsigned long));
	else if (c == 'd' || c == 'i')
		i += ft_printd(va_arg(args, int));
	else if (c == 'u')
		i += ft_printd(va_arg(args, unsigned int));
	else if (c == 'x')
		i += ft_putnbr_hex(va_arg(args, unsigned int));
	else if (c == 'X')
		i += ft_hex_upper(va_arg(args, unsigned int));
	else
	{
		i += ft_charprint('%');
		i += ft_charprint(c);
	}
	return (i);
}

int	ft_printf(const char *str, ...)
{
	size_t	i;
	va_list	ap;
	int		length;

	i = 0;
	length = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += ft_format(str[i + 1], ap);
			i++;
		}
		else
		{
			ft_charprint(str[i]);
			length++;
		}
		i++;
	}
	va_end(ap);
	return (length);
}
/*
#include<stdio.h>

int	main()
{
	ft_printf(" %d %d%%%%%k", -2147483647, 0);
	printf("\n %d %d%%%%%k", -2147483647, 0);
}*/
