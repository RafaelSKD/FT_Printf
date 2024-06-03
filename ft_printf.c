/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaefer <rafaefer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:16:57 by rafaefer          #+#    #+#             */
/*   Updated: 2024/06/03 11:42:55 by rafaefer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *format, int i, va_list ap)
{
	if (format[i + 1] == '%')
		return (ft_putchar(format[i + 1]));
	else if (format[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (format[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (format[i + 1] == 'd' || format[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (format[i + 1] == 'u')
		return (putnbr_u(va_arg(ap, unsigned int)));
	else if (format[i + 1] == 'x' || format[i + 1] == 'X')
	{
		if (format[i + 1] == 'X')
			return (put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (format[i + 1] == 'p')
		return (put_pointer(va_arg(ap, void *), \
				"0123456789abcdef"));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		impr;

	va_start(ap, format);
	i = 0;
	impr = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			impr += ft_printf_arg(format, i, ap);
			i++;
		}
		else
			impr += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (impr);
}
