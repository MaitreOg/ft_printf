/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:58:04 by smarty            #+#    #+#             */
/*   Updated: 2023/10/27 21:10:20 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i += ft_putchar(s[i]);
	return (i);
}

int	putnbr(int n)
{
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		i = 11;
	}
	if (n != -2147483648 && n < 0)
	{
		i = ft_putchar('-');
		n *= -1;
	}
	if (n > 9)
	{
		i += putnbr(n / 10);
		i += putnbr(n % 10);
	}
	else if (n >= 0)
	{
		i += ft_putchar(n + '0');
	}
	return (i);
}

int	ft_print_comb(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len = ft_putchar(va_arg(arg, int));
	if (c == 's')
		len = ft_putstr(va_arg(arg, char *));
	if (c == 'p')
		len += putptr(va_arg(arg, unsigned long long));
	if (c == 'd')
		len = putnbr(va_arg(arg, int));
	if (c == 'u')
		len = uputnbr(va_arg(arg, unsigned int));
	if (c == 'i')
		len += putnbr(va_arg(arg, int));
	if (c == 'x')
		len = hexanbr(va_arg(arg, unsigned int));
	if (c == 'X')
		len = hexanbrm(va_arg(arg, unsigned int));
	if (c == '%')
		len = ft_putchar('%');
	return (len);
}

int	ft_printf(const char *print, ...)
{
	int		i;
	int		y;
	va_list	arg;

	va_start(arg, print);
	i = 0;
	y = 0;
	while (print[i])
	{
		while (print[i] && print[i] != '%')
		{
			i += ft_putchar(print[i]);
			y++;
		}
		if (print[i] == '%')
		{
			i++;
			y = y + ft_print_comb(print[i], arg);
			i++;
		}
	}
	return (y);
}

/*int main()
{
	char	*ptr;

	ptr = "coucou";

	printf(" %p ", ptr) ;
	printf("\n");
	ft_printf(" %p ", ptr);
	printf("\n");
	printf("\n");
	printf(" %s ", "yooo") ;
	printf("\n");
	ft_printf(" %s ", "yooo");
	printf("\n");
	printf("\n");
	printf(" %u ", 123456) ;
	printf("\n");
	ft_printf(" %u ", 123456);
	printf("\n");
	printf("\n");
	printf(" %% ") ;
	printf("\n");
	ft_printf(" %% ");
	printf("\n");
	printf("\n");
	printf(" %x ", 1222) ;
	printf("\n");
	ft_printf(" %x ", 1222);
	
	
	return (0);
}*/