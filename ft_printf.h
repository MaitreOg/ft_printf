/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smarty <smarty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 14:46:15 by smarty            #+#    #+#             */
/*   Updated: 2023/10/18 12:59:16 by smarty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int	ft_printf(const char *print, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_print_comb(char c, va_list arg);
int	putnbr(int n);
int	uputnbr(unsigned int n);
int	hexanbr(unsigned int n);
int	hexanbrm(unsigned int n);
int	putptr(unsigned long long ptr);
int	putptr2(unsigned long long n);
#endif /*ft_printf*/
