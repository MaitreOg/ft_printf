/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 20:32:48 by smarty            #+#    #+#             */
/*   Updated: 2023/10/27 21:07:05 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putptr2(unsigned long long n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += putptr2(n / 16);
		i += putptr2(n % 16);
	}
	else if (n <= 9)
		i += ft_putchar(n % 16 + '0');
	else
		i += ft_putchar(n % 16 - 10 + 'a');
	return (i);
}

int	putptr(unsigned long long ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += putptr2(ptr);
	return (i);
}

int	uputnbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 9)
	{
		i += uputnbr(n / 10);
		i += uputnbr(n % 10);
	}
	else
		i += ft_putchar(n + '0');
	return (i);
}

int	hexanbr(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += hexanbr(n / 16);
		i += hexanbr(n % 16);
	}
	else if (n < 10)
		i += ft_putchar(n % 16 + '0');
	else
		i += ft_putchar(n % 16 - 10 + 'a');
	return (i);
}

int	hexanbrm(unsigned int n)
{
	int	i;

	i = 0;
	if (n >= 16)
	{
		i += hexanbrm(n / 16);
		i += hexanbrm(n % 16);
	}
	else if (n < 10)
		i += ft_putchar(n % 16 + '0');
	else
		i += ft_putchar(n % 16 - 10 + 'A');
	return (i);
}
