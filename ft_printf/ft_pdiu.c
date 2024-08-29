/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pdiu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsharame <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 12:41:56 by hsharame          #+#    #+#             */
/*   Updated: 2024/06/11 15:43:27 by hsharame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printd(long int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_charprint('-');
		n = -n;
	}
	if (n >= 10)
	{
		i += ft_printd(n / 10);
		i += ft_charprint(n % 10 + '0');
	}
	else
		i += ft_charprint(n + '0');
	return (i);
}

int	ft_printu(int n)
{
	int	i;

	i = 0;
	if (n >= 0)
		i += ft_printd(n);
	else
	{
		n = 4294967296 - n;
		i += ft_printd(n);
	}
	return (i);
}
